/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:40:59 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/03 15:48:02 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_map_image_buffer(t_cub *cub)
{
	// if (cub->dup_map.img_ptr)
	// 	mlx_destroy_image(cub->mlx, cub->dup_map.img_ptr);
	cub->dup_map.img_ptr = mlx_new_image(cub->mlx,
			MAP_WIDTH * MAP_SIZE, MAP_HEIGHT * MAP_SIZE);
	cub->dup_map.img_pixels_ptr = mlx_get_data_addr(cub->dup_map.img_ptr,
			&cub->dup_map.bits_per_pixel, &cub->dup_map.line_length,
			&cub->dup_map.endian);
}

void	dup_map(t_cub *cub)
{
	init_map_image_buffer(cub);
	t_pointi	pos;
	int			color;

	pos.y = 0;
	while (pos.y < MAP_HEIGHT * MAP_SIZE)
	{
		pos.x = 0;
		while (pos.x < MAP_WIDTH * MAP_SIZE)
		{
			*(unsigned int *)(cub->dup_map.img_pixels_ptr
				+ (pos.y * cub->dup_map.line_length + pos.x * (cub->dup_map.bits_per_pixel / 8)))
				= *(unsigned int *)(cub->img.img_pixels_ptr
				+ (pos.y * cub->img.line_length + pos.x * (cub->img.bits_per_pixel / 8)));
			pos.x++;
		}
		pos.y++;
	}
}

void	init_image(t_cub *cub)
{
	ft_memset(cub->img.img_pixels_ptr, 0,
		HEIGHT * cub->img.line_length);
	draw_map(cub);
	dup_map(cub);
	draw_player(cub);
	show_fps(cub);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img_ptr, 0, 0);
}

void reset_player(t_cub *cub)
{
	// draw_square(cub, cub->p.prev_x - (cub->p.half), cub->p.prev_y - (cub->p.half), cub->p.size, 0x00ff00);
	t_pointi	incr_pos;
	t_pointi	norm_pos;
	int			color;

	norm_pos.y = (int)cub->p.prev_y - (cub->p.half);
	norm_pos.x = (int)cub->p.prev_x - (cub->p.half);
	incr_pos.y = 0;
	while (incr_pos.y < cub->p.size)
	{
		incr_pos.x = 0;
		while (incr_pos.x < cub->p.size)
		{
			color = *(unsigned int *)(cub->dup_map.img_pixels_ptr
					+ (norm_pos.y * cub->dup_map.line_length + norm_pos.x * (cub->dup_map.bits_per_pixel / 8)));
			put_pixel(cub, (norm_pos.x + incr_pos.x),
				(norm_pos.y + incr_pos.y), color);
			incr_pos.x++;
		}
		incr_pos.y++;
	}
}

void reset_player(t_cub *cub)
{
	draw_square(cub, cub->p.prev_x - (cub->p.half), cub->p.prev_y - (cub->p.half), cub->p.size, 0x000000);
	// TODO: the detailed implementation
	// t_pointi	incr_pos;
	// t_pointi	norm_pos;

	// norm_pos.y = (int)cub->p.prev_y - (cub->p.half);
	// norm_pos.x = (int)cub->p.prev_x - (cub->p.half);
	// incr_pos.y = 0;
	// while (incr_pos.y < cub->p.size)
	// {
	// 	incr_pos.x = 0;
	// 	while (incr_pos.x < cub->p.size)
	// 	{
	// 		put_pixel(cub, (norm_pos.x + incr_pos.x),
	// 			(norm_pos.y + incr_pos.y), 0x000000);
	// 		incr_pos.x++;
	// 	}
	// 	incr_pos.y++;
	// }
}
