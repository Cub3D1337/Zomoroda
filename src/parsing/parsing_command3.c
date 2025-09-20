/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:40:40 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/19 16:23:54 by hwahmane         ###   ########.fr       */
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
	if (out[0] != -1)
		return (error("Error\nDuplicate color\n"));
	if (!parse_component(&s, &out[0], 'R') || !skip_comma(&s))
		return (0);
	if (!parse_component(&s, &out[1], 'G') || !skip_comma(&s))
		return (0);
	if (!parse_component(&s, &out[2], 'B'))
		return (0);
	if (!check_trailing(s))
		return (0);
	return (1);
}

int	is_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr(" 01NSEWD", line[i]))
			return (0);
		i++;
	}
	return (!is_all_space(line));
}

void	fill_row(char *dst, char *src, int w)
{
	int	j;
	int	len;

	len = ft_strlen(src);
	j = 0;
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
	cfg->map_h = raw->size;
	cfg->map_w = get_max_width(raw);
	cfg->map = (char **)malloc(sizeof(char *) * cfg->map_h);
	if (!cfg->map)
		return (error("Error\nOOM\n"));
	return (alloc_map_rows(cfg, raw));
}
