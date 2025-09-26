/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:40:18 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/23 14:23:39 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	error(const char *msg)
{
	fdprintf(2, "%s", msg);
	return (0);
}

void	vec_init(t_vec *v)
{
	v->data = NULL;
	v->size = 0;
	v->cap = 0;
}

int	vec_push(t_vec *v, char *line)
{
	int		newcap;
	char	**nd;
	int		i;

	if (v->size + 1 > v->cap)
	{
		if (v->cap == 0)
			newcap = 8;
		else
			newcap = v->cap * 2;
		nd = (char **)malloc(sizeof(char *) * newcap);
		if (!nd)
			return (0);
		i = 0;
		while (i < v->size)
		{
			nd[i] = v->data[i];
			i++;
		}
		free(v->data);
		v->data = nd;
		v->cap = newcap;
	}
	v->data[v->size++] = line;
	return (1);
}

void	vec_free(t_vec *v)
{
	int	i;

	i = 0;
	while (i < v->size)
	{
		free(v->data[i]);
		i++;
	}
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->cap = 0;
}

int	rstrip_newline(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
	{
		s[len - 1] = '\0';
		return (1);
	}
	return (0);
}
