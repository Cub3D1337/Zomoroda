/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:43:09 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/27 00:17:26 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	skip_spaces(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	return (*i);
}

int	parse_identifier_line(char *line, t_config *cfg, int i)
{
	if (!ft_strncmp(&line[i], "NO", 2) && (line[i + 2] == ' '
			|| line[i + 2] == '\t'))
		return (set_texture(&cfg->no_texture, &line[i + 2], "NO"));
	if (!ft_strncmp(&line[i], "SO", 2) && (line[i + 2] == ' '
			|| line[i + 2] == '\t'))
		return (set_texture(&cfg->so_texture, &line[i + 2], "SO"));
	if (!ft_strncmp(&line[i], "WE", 2) && (line[i + 2] == ' '
			|| line[i + 2] == '\t'))
		return (set_texture(&cfg->we_texture, &line[i + 2], "WE"));
	if (!ft_strncmp(&line[i], "EA", 2) && (line[i + 2] == ' '
			|| line[i + 2] == '\t'))
		return (set_texture(&cfg->ea_texture, &line[i + 2], "EA"));
	return (2);
}

int	parse_color_line(char *line, t_config *cfg, int i)
{
	if (line[i] == 'F' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (parse_rgb(&line[i + 1], cfg->floor_rgb));
	if (line[i] == 'C' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (parse_rgb(&line[i + 1], cfg->ceil_rgb));
	return (2);
}

int	parse_line_before_map(char *line, t_config *cfg)
{
	int	i;
	int	color;
	int	texture;

	i = 0;
	skip_spaces(line, &i);
	if (line[i] == '\0')
	{
		if (i > 0 && (line[i - 1] == '\t' || line[i - 1] == ' '))
			return (error("Error\nInvalid space-only line before map\n"));
		return (1);
	}
	texture = parse_identifier_line(line, cfg, i);
	if (texture == 0)
		return (0);
	else if (texture == 1)
		return (1);
	color = parse_color_line(line, cfg, i);
	if (color == 0)
		return (0);
	else if (color == 1)
		return (1);
	return (2);
}

int	is_inside(int x, int y, const t_config *cfg)
{
	return (y >= 0 && y < cfg->map_h && x >= 0 && x < cfg->map_w);
}
