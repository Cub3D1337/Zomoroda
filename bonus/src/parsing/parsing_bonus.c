/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:41:59 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/27 00:08:09 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	open_file(int ac, char **av, int *fd)
{
	if (ac != 2)
		return (error("Error\nWrong number of arguments\n"));
	if (!check_extension(av))
		return (0);
	*fd = open(av[1], O_RDONLY);
	if (*fd < 0)
		return (error("Error\nCould not open file\n"));
	return (1);
}

int	handle_map_line(char *line, t_config *cfg, int *seen_map, int fd)
{
	*seen_map = 1;
	if (!collect_map(fd, line, cfg))
	{
		free_all(fd);
		free_config(cfg);
		close(fd);
		return (0);
	}
	return (2);
}

int	handle_line_before_map(char *line, t_config *cfg, int *seen_map, int fd)
{
	int	r;

	r = parse_line_before_map(line, cfg);
	if (r == 0)
	{
		free(line);
		free_all(fd);
		free_config(cfg);
		close(fd);
		return (0);
	}
	if (r == 2)
	{
		if (is_map_line(line))
			return (handle_map_line(line, cfg, seen_map, fd));
		free(line);
		free_all(fd);
		free_config(cfg);
		close(fd);
		return (error("Error\nInvalid line before map\n"));
	}
	free(line);
	return (1);
}

int	parsing(int ac, char **av, t_config *cfg)
{
	int		fd;
	char	*line;
	int		seen_map;

	seen_map = 0;
	if (!open_file(ac, av, &fd))
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		rstrip_newline(line);
		if (handle_line_before_map(line, cfg, &seen_map, fd) == 0)
			return (0);
		line = get_next_line(fd);
	}
	close(fd);
	if (!validate_once_all_present(cfg))
		return (free_config(cfg), 0);
	if (!validate_player_and_close(cfg))
		return (free_config(cfg), 0);
	return (1);
}
