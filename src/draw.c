/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/07/28 14:35:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_square(t_cub *cub, int x, int y, int size, int color)
{
	t_pointi	incr_pos;

	incr_pos.y = 0;
	while (incr_pos.y < size)
	{
		incr_pos.x = 0;
		while (incr_pos.x < size)
		{
			put_pixel(cub, (x + incr_pos.x), (y + incr_pos.y), color);
			incr_pos.x++;
		}
		incr_pos.y++;
	}
}

void	draw_map(t_cub *cub)
{
	t_pointi	pos;
	int			color;

	pos.y = 0;
	while (pos.y < MAP_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < MAP_WIDTH)
		{
			if (cub->map.array[pos.y][pos.x] == 1)
				color = 0xffffff;
			else if (cub->map.array[pos.y][pos.x] == 2)
				color = 0xffff00;
			else
				color = 0x000000;
			draw_square(cub, pos.x * MAP_SIZE, pos.y * MAP_SIZE, MAP_SIZE, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_player(t_cub *cub)
{
	draw_square(cub, cub->p.x - (cub->p.half), cub->p.y - (cub->p.half), cub->p.size, 0xff0000);
}

void	draw(t_cub *cub)
{
	ft_memset(cub->img.img_pixels_ptr, 0,
		HEIGHT * cub->img.line_length);
	draw_map(cub);
	draw_player(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img_ptr, 0, 0);
}
