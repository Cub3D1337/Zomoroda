/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:40:40 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/23 13:40:42 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	read_int(const char **s, int *out)
{
	long	val;
	int		digits;

	val = 0;
	digits = 0;
	while (**s == ' ' || **s == '\t')
		(*s)++;
	while (ft_isdigit(**s))
	{
		val = val * 10 + (**s - '0');
		(*s)++;
		digits++;
	}
	if (digits == 0 || val > 255)
		return (0);
	*out = (int)val;
	while (**s == ' ' || **s == '\t')
		(*s)++;
	return (1);
}

int	parse_rgb(const char *s, int out[3])
{
	int	r;
	int	g;
	int	b;

	if (!read_int(&s, &r))
		return (error("Error\nInvalid RGB (R)\n"));
	if (*s != ',')
		return (error("Error\nInvalid RGB: missing comma\n"));
	s++;
	if (!read_int(&s, &g))
		return (error("Error\nInvalid RGB (G)\n"));
	if (*s != ',')
		return (error("Error\nInvalid RGB: missing comma\n"));
	s++;
	if (!read_int(&s, &b))
		return (error("Error\nInvalid RGB (B)\n"));
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s != '\0' && *s != '\n')
		return (error("Error\nInvalid RGB: trailing chars\n"));
	out[0] = r;
	out[1] = g;
	out[2] = b;
	return (1);
}

int	is_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr(" 01NSEW", line[i]))
			return (0);
		i++;
	}
	return (!is_all_space(line));
}

void	fill_row(char *dst, char *src, int w)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(src);
	while (j < w)
	{
		if (j < len)
			dst[j] = src[j];
		else
			dst[j] = ' ';
		j++;
	}
	dst[w] = '\0';
}

int	build_rect_map(t_config *cfg, t_vec *raw)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (i < raw->size)
	{
		if ((int)ft_strlen(raw->data[i]) > w)
			w = ft_strlen(raw->data[i]);
		i++;
	}
	cfg->map_h = raw->size;
	cfg->map_w = w;
	cfg->map = (char **)malloc(sizeof(char *) * cfg->map_h);
	if (!cfg->map)
		return (error("Error\nOOM\n"));
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
