/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:40:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/26 22:31:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cell_neighbors(t_config *cfg, int x, int y)
{
	if (is_inside(x + 1, y, cfg) && cfg->map[y][x + 1] == ' ')
		return (error("Error\nMap not closed (neighbor issue)\n"));
	if (is_inside(x - 1, y, cfg) && cfg->map[y][x - 1] == ' ')
		return (error("Error\nMap not closed (neighbor issue)\n"));
	if (is_inside(x, y + 1, cfg) && cfg->map[y + 1][x] == ' ')
		return (error("Error\nMap not closed (neighbor issue)\n"));
	if (is_inside(x, y - 1, cfg) && cfg->map[y - 1][x] == ' ')
		return (error("Error\nMap not closed (neighbor issue)\n"));
	return (1);
}

int	check_row(t_config *cfg, int y, int x)
{
	if (x >= cfg->map_w)
		return (1);
	if (cfg->map[y][x] == '0' || ft_strchr("NSEW", cfg->map[y][x]))
		if (!check_cell_neighbors(cfg, x, y))
			return (0);
	return (check_row(cfg, y, x + 1));
}

int	check_cell_player(t_config *cfg, int x, int y, int *pc)
{
	char	c;

	c = cfg->map[y][x];
	if (!ft_strchr(" 01NSEW", c))
		return (error("Error\nInvalid character in map\n"));
	if (ft_strchr("NSEW", c))
	{
		(*pc)++;
		cfg->player_x = x;
		cfg->player_y = y;
		cfg->player_dir = c;
	}
	return (1);
}

int	check_row_player(t_config *cfg, int y, int x, int *pc)
{
	if (x >= cfg->map_w)
		return (1);
	if (!check_cell_player(cfg, x, y, pc))
		return (0);
	return (check_row_player(cfg, y, x + 1, pc));
}
