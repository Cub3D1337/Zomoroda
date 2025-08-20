/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:02:58 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/19 18:07:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(unsigned int *)(cub->img.img_pixels_ptr
		+ (y * cub->img.line_length + x * cub->img.bytes_per_pixel))
		= color;
}

double	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

void   get_player_pos(t_cub *cub)
{
    t_pointi	pos;

	pos.y = 0;
	while (pos.y < MAP_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < MAP_WIDTH)
		{
			if (cub->map.array[pos.y][pos.x] == 2)
			
			{
				cub->p.pos.x = (pos.x * MAP_SIZE) + (MAP_SIZE / 2);
				cub->p.pos.y = (pos.y * MAP_SIZE) + (MAP_SIZE / 2);
                return ;
			}
			pos.x++;
		}
		pos.y++;
	}
}
