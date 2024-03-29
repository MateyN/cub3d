/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:11:26 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/05 10:55:30 by krioja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_width(char *line)
{
	int	lenght;

	lenght = ft_strlen(line);
	return (lenght * TILES);
}

/**
@brief Checks if the player can move to the specified position.
@param map The game map.
@param x The x position to check.
@param y The y position to check.
@return returns 1 if the player can move, 0 otherwise.
*/
int	can_move(t_map *map, double x, double y)
{
	int	x2;
	int	y2;

	x2 = floor(x / TILES);
	y2 = floor(y / TILES);
	if (y < 0 || y > map->map_size_y)
		return (0);
	if (x < 0 || x > get_width(map->map[y2]))
		return (0);
	if (map->map[y2][x2] != '1')
		return (1);
	return (0);
}

/**
@brief Moves the player in the direction of the player's movement.
@param game The game struct.
*/
void	move_player(t_game *game)
{
	double	step_x;
	double	step_y;
	double	forward;
	double	sideways;

	step_x = 0;
	step_y = 0;
	game->player->angle += game->player->rotdir * game->player->rotspeed;
	forward = game->player->move * game->player->movespeed;
	sideways = game->player->side * 2.5;
	step_x = step_x + (cos(game->player->angle) * forward);
	step_x = step_x + (cos(game->player->angle + PI / 2) * sideways);
	step_y = step_y + (sin(game->player->angle) * forward);
	step_y = step_y + (sin(game->player->angle + PI / 2) * sideways);
	if (can_move(game->map, game->player->x + step_x, game->player->y))
		game->player->x += step_x;
	if (can_move(game->map, game->player->x, game->player->y + step_y))
		game->player->y += step_y;
}
