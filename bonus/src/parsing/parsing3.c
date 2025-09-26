/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:43:28 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/26 23:48:50 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	push_line(t_vec *raw, char *line)
{
	rstrip_newline(line);
	if (!vec_push(raw, line))
	{
		free(line);
		return (0);
	}
	return (1);
}

int	read_map_lines(int fd, t_vec *raw)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!process_line(raw, line))
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}

int	collect_map(int fd, char *first_line, t_config *cfg)
{
	t_vec	raw;

	vec_init(&raw);
	if (!push_line(&raw, first_line))
	{
		free(first_line);
		return (error("Error\nOOM\n"));
	}
	if (!read_map_lines(fd, &raw))
	{
		vec_free(&raw);
		return (error("Error\nInvalid map lines\n"));
	}
	if (raw.size == 0)
	{
		vec_free(&raw);
		return (error("Error\nEmpty map\n"));
	}
	if (!build_rect_map(cfg, &raw))
	{
		vec_free(&raw);
		return (0);
	}
	free(raw.data);
	return (1);
}

int	check_neighbors(t_config *cfg)
{
	int	y;

	y = 0;
	if (cfg->map_h <= 0)
		return (1);
	while (y < cfg->map_h)
	{
		if (!check_row(cfg, y, 0))
			return (0);
		y++;
	}
	return (1);
}

int	validate_player_and_close(t_config *cfg)
{
	int	px;
	int	py;

	px = -1;
	py = -1;
	if (!check_player_spawn(cfg, &px, &py))
		return (0);
	cfg->player_x = px;
	cfg->player_y = py;
	if (!check_map_edges(cfg))
		return (0);
	if (!check_neighbors(cfg))
		return (0);
	return (1);
}
