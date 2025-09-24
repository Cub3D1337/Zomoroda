/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:48:20 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 22:48:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	check_boundaries(t_cub *cub)
{
	t_pointi	ply_corners[4];
	t_pointi	map;
	t_pointd	p;
	t_pointi	i_h;

	p = (t_pointd){cub->p.pos.x, cub->p.pos.y};
	i_h = (t_pointi){0, cub->p.half};
	if ((int)p.x - i_h.y < BLOCK_SIZE || (int)p.y - i_h.y < BLOCK_SIZE
		|| (int) p.x + i_h.y >= (cub->map.w * BLOCK_SIZE) + 1 - BLOCK_SIZE
		|| (int)p.y + i_h.y >= (cub->map.h * BLOCK_SIZE) + 1 - BLOCK_SIZE)
		return (false);
	ply_corners[0] = (t_pointi){(int)(p.x - i_h.y), (int)(p.y - i_h.y)};
	ply_corners[1] = (t_pointi){(int)(p.x + i_h.y - 1), (int)(p.y - i_h.y)};
	ply_corners[2] = (t_pointi){(int)(p.x - i_h.y), (int)(p.y + i_h.y - 1)};
	ply_corners[3] = (t_pointi){(int)(p.x + i_h.y - 1), (int)(p.y + i_h.y - 1)};
	while (i_h.x < 4)
	{
		map.x = ply_corners[i_h.x].x / BLOCK_SIZE;
		map.y = ply_corners[i_h.x].y / BLOCK_SIZE;
		if (cub->map.array[map.y][map.x] == '1'
		|| cub->map.array[map.y][map.x] == 'D')
			return (false);
		i_h.x++;
	}
	return (true);
}
