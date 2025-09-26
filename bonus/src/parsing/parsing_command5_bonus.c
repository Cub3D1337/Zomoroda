/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command5_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:41:03 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/27 00:17:26 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	validate_once_all_present(const t_config *cfg)
{
	if (!cfg->no_texture || !cfg->so_texture || !cfg->we_texture
		|| !cfg->ea_texture)
		return (error("Error\nMissing one or more texture paths\n"));
	if (cfg->floor_rgb[0] < 0 || cfg->ceil_rgb[0] < 0)
		return (error("Error\nMissing floor/ceiling color\n"));
	if (!cfg->map || cfg->map_h == 0 || cfg->map_w == 0)
		return (error("Error\nMissing map\n"));
	return (1);
}

int	check_column_top_bottom(t_config *cfg, int x)
{
	if (x >= cfg->map_w)
		return (1);
	if (cfg->map[0][x] == '0' || ft_strchr("NSEWD", cfg->map[0][x]))
		return (error("Error\nMap not closed at top edge\n"));
	if (cfg->map[cfg->map_h - 1][x] == '0' || ft_strchr("NSEWD",
			cfg->map[cfg->map_h - 1][x]))
		return (error("Error\nMap not closed at bottom edge\n"));
	return (check_column_top_bottom(cfg, x + 1));
}

int	check_row_sides(t_config *cfg, int y)
{
	if (y >= cfg->map_h)
		return (1);
	if (cfg->map[y][0] == '0' || ft_strchr("NSEWD", cfg->map[y][0]))
		return (error("Error\nMap not closed at left edge\n"));
	if (cfg->map[y][cfg->map_w - 1] == '0' || ft_strchr("NSEWD",
			cfg->map[y][cfg->map_w - 1]))
		return (error("Error\nMap not closed at right edge\n"));
	return (check_row_sides(cfg, y + 1));
}

int	check_gate(t_config *cfg, int x, int y)
{
	if (y == 0 || y == cfg->map_h - 1)
		return (1);
	if (cfg->map[y][x] == 'D' && !((cfg->map[y][x - 1] == '1' && cfg->map[y][x
				+ 1] == '1') || (cfg->map[y - 1][x] == '1' && cfg->map[y
				+ 1][x] == '1')))
		return (error("Error\nGate must be placed between two walls\n"));
	return (1);
}
