/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:19 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/20 11:07:40 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
    char    *dst;
    int     bits_per_pixel;
    int     size_line;
    int     endian;

    dst = mlx_get_data_addr(game->img, &bits_per_pixel, &size_line, &endian);
    if (x >= 0 && x < game->map_size_x * MAPWIDTH && y >= 0 && y < game->map_size_y * MAPHEIGHT)
    {
        int offset = y * size_line + x * (bits_per_pixel / 8);
        *(unsigned int*)(dst + offset) = color;
    }
}

void	read_img(t_game *game)
{
	int	width;
	int	height;
    
	game->wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall32x32.xpm", &width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./assets/square.xpm", &width, &height);
}

void    my_mlx_put_image_to_window(t_game *game, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while (i < MAPHEIGHT)
    {
        j = 0;
        while (j < MAPWIDTH)
        {
            my_mlx_pixel_put(game, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void    render(t_game *game)
{
    fill_map(game);
    draw_rays(game);
    draw_player(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}