/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:44:45 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/19 16:39:54 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*trim_texture_path(const char *path)
{
	char	*p;
	int		len;

	if (!path)
		return (NULL);
	while (*path == ' ' || *path == '\t')
		path++;
	p = ft_strdup(path);
	if (!p)
		return (NULL);
	len = ft_strlen(p);
	while (len > 0 && (p[len - 1] == ' ' || p[len - 1] == '\t'
			|| p[len - 1] == '\n' || p[len - 1] == '\r'))
		p[--len] = '\0';
	if (len == 0)
	{
		free(p);
		return (NULL);
	}
	return (p);
}

int	validate_texture_file(const char *path, const char *id)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		fdprintf(2, "Error\nCannot open %s texture file: %s\n", id, path);
		return (0);
	}
	close(fd);
	return (1);
}

int	set_texture(char **slot, const char *path_start, const char *id)
{
	char	*p;

	if (*slot)
		return (error("Error\nDuplicate texture identifier\n"));
	p = trim_texture_path(path_start);
	if (!p)
		return (error("Error\nEmpty texture path\n"));
	if (!validate_texture_file(p, id))
	{
		free(p);
		return (0);
	}
	*slot = p;
	return (1);
}

int	check_player_spawn(t_config *cfg, int *px, int *py)
{
	int	pc;
	int	*pos[3];
	int	y;
	int	x;

	pc = 0;
	pos[0] = px;
	pos[1] = py;
	pos[2] = &pc;
	y = 0;
	while (y < cfg->map_h)
	{
		x = 0;
		while (x < cfg->map_w)
		{
			if (!check_cell(cfg, x, y, pos))
				return (0);
			x++;
		}
		y++;
	}
	if (pc != 1)
		return (error("Error\nThere must be exactly one player spawn\n"));
	return (1);
}

int	check_map_edges(t_config *cfg)
{
	if (!check_column_top_bottom(cfg, 0))
		return (0);
	if (!check_row_sides(cfg, 0))
		return (0);
	return (1);
}
