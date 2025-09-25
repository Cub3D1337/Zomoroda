/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:29:04 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/25 22:44:09 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	skip_trailing_spaces(int fd, char *line)
{
	while (line)
	{
		rstrip_newline(line);
		if (!is_all_space(line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	process_line(int fd, t_vec *raw, char *line)
{
	rstrip_newline(line);
	if (!is_map_line(line))
	{
		if (!is_all_space(line))
		{
			free(line);
			return (0);
		}
		free(line);
		return (skip_trailing_spaces(fd, get_next_line(fd)));
	}
	if (!push_line(raw, line))
		return (0);
	return (1);
}

int	check_cell(t_config *cfg, int x, int y, int *pos[3])
{
	char	c;

	c = cfg->map[y][x];
	if (!ft_strchr(" 01NSEWD", c))
		return (error("Error\nInvalid character in map\n"));
	if (ft_strchr("NSEW", c))
	{
		(*pos[2])++;
		*pos[0] = x;
		*pos[1] = y;
		cfg->player_dir = c;
	}
	if (!check_gate(cfg, x, y))
		return (0);
	return (1);
}

// void	free_config(t_config *cfg)
// {
// 	if (!cfg)
// 		return;

// 	if (cfg->no_texture)
// 	{
// 		free(cfg->no_texture);
// 		cfg->no_texture = NULL;
// 	}
// 	if (cfg->so_texture)
// 	{
// 		free(cfg->so_texture);
// 		cfg->so_texture = NULL;
// 	}
// 	if (cfg->we_texture)
// 	{
// 		free(cfg->we_texture);
// 		cfg->we_texture = NULL;
// 	}
// 	if (cfg->ea_texture)
// 	{
// 		free(cfg->ea_texture);
// 		cfg->ea_texture = NULL;
// 	}

// 	if (cfg->map)
// 	{
// 		for (int i = 0; cfg->map[i]; i++)
// 			free(cfg->map[i]);
// 		free(cfg->map);
// 		cfg->map = NULL;
// 	}
// }
