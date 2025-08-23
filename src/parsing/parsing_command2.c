/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:40:29 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/23 14:09:00 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void init_config(t_config *cfg)
{
	cfg->no_texture = NULL;
	cfg->so_texture = NULL;
	cfg->we_texture = NULL;
	cfg->ea_texture = NULL;
	cfg->floor_rgb[0] = -1;
	cfg->floor_rgb[1] = -1;
	cfg->floor_rgb[2] = -1;
	cfg->ceil_rgb[0] = -1;
	cfg->ceil_rgb[1] = -1;
	cfg->ceil_rgb[2] = -1;
	cfg->map = NULL;
	cfg->map_h = 0;
	cfg->map_w = 0;
	cfg->player_x = -1;
	cfg->player_y = -1;
	cfg->player_dir = '0';
}

void free_config(t_config *cfg)
{
	int i;

	if (cfg->no_texture)
		free(cfg->no_texture);
	if (cfg->so_texture)
		free(cfg->so_texture);
	if (cfg->we_texture)
		free(cfg->we_texture);
	if (cfg->ea_texture)
		free(cfg->ea_texture);
	if (cfg->map)
	{
		i = 0;
		while (i < cfg->map_h)
			free(cfg->map[i++]);
		free(cfg->map);
	}
}

int check_extension(char **av)
{
	const char *ext;
	int len;

	ext = ".cub";
	if (!av || !av[1])
		return (error("Error\nMissing file argument\n"));
	len = ft_strlen(av[1]);
	if (len < 5)
		return (error("Error\nInvalid file extension\n"));
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'c' || av[1][len - 2] != 'u'
		|| av[1][len - 1] != 'b')
		return (error("Error\nThe extension must be .cub\n"));
	return (1);
}

int is_all_space(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\r'
			&& s[i] != '\v' && s[i] != '\f')
			return (0);
		i++;
	}
	return (1);
}

void free_split(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
