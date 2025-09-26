/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:13:46 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/26 22:31:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_width(t_vec *raw)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (i < raw->size)
	{
		if ((int)ft_strlen(raw->data[i]) > w)
			w = ft_strlen(raw->data[i]);
		i++;
	}
	return (w);
}

int	alloc_map_rows(t_config *cfg, t_vec *raw)
{
	int	i;

	i = 0;
	while (i < cfg->map_h)
	{
		cfg->map[i] = (char *)ft_calloc(cfg->map_w + 1, sizeof(char));
		if (!cfg->map[i])
			return (error("Error\nOOM\n"));
		fill_row(cfg->map[i], raw->data[i], cfg->map_w);
		free(raw->data[i]);
		i++;
	}
	return (1);
}

int	skip_comma(const char **s)
{
	if (**s != ',')
		return (error("Error\nInvalid RGB: missing comma\n"));
	(*s)++;
	return (1);
}

int	parse_component(const char **s, int *val, char comp)
{
	if (!read_int(s, val))
	{
		if (comp == 'R')
			return (error("Error\nInvalid RGB (R)\n"));
		if (comp == 'G')
			return (error("Error\nInvalid RGB (G)\n"));
		return (error("Error\nInvalid RGB (B)\n"));
	}
	return (1);
}

int	check_trailing(const char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s != '\0' && *s != '\n')
		return (error("Error\nInvalid RGB: trailing chars\n"));
	return (1);
}
