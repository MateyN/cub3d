/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:42:16 by mnikolov          #+#    #+#             */
/*   Updated: 2023/04/13 10:44:07 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update(t_game *game)
{
	move_player(game);
	draw_rays(game);
	generate_3d_projection(game);
}

int	loop_hook(t_game *game)
{
	update(game);
	render(game);
	return (0);
}

void	set_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 0, ft_press_key, game);
	mlx_hook(game->win, 3, 0, ft_release_key, game);
	mlx_hook(game->win, 17, 0, ft_close, game);
}

void	set_game(t_game *game)
{
	game->image->img = mlx_new_image(game->mlx, MAPWIDTH, MAPHEIGHT);
	game->image->addr = mlx_get_data_addr(game->image->img, &game->image->bits_per_pixel,
			&game->image->line_length, &game->image->endian);
	game->map->width = MAPWIDTH;
	game->map->height = MAPHEIGHT;
}

void	ft_game(t_game *game)
{
	set_hooks(game);
	set_game(game);
}