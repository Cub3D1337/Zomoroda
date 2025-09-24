/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:40:59 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 22:04:05 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_map_image_buffer(t_cub *cub)
{
	// if (cub->dup_map.img_ptr)
	// 	mlx_destroy_image(cub->mlx, cub->dup_map.img_ptr);
	cub->dup_map.img_ptr = mlx_new_image(cub->mlx,
			MAP_WIDTH * BLOCK_SIZE, MAP_HEIGHT * BLOCK_SIZE);
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
	while (pos.y < MAP_HEIGHT * BLOCK_SIZE)
	{
		pos.x = 0;
		while (pos.x < MAP_WIDTH * BLOCK_SIZE)
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
	// draw_square(cub, cub->p.prev_pos.x - (cub->p.half), cub->p.prev_pos.y - (cub->p.half), cub->p.size, 0x00ff00);
	t_pointi	incr_pos;
	t_pointi	norm_pos;
	int			color;

	norm_pos.y = (int)cub->p.prev_pos.y - (cub->p.half);
	norm_pos.x = (int)cub->p.prev_pos.x - (cub->p.half);
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
	draw_square(cub, cub->p.prev_pos.x - (cub->p.half), cub->p.prev_pos.y - (cub->p.half), cub->p.size, 0x000000);
	// TODO: the detailed implementation
	// t_pointi	incr_pos;
	// t_pointi	norm_pos;

	// norm_pos.y = (int)cub->p.prev_pos.y - (cub->p.half);
	// norm_pos.x = (int)cub->p.prev_pos.x - (cub->p.half);
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

// Convert world pos -> minimap pos
t_pointd	world_to_minimap(t_cub *cub, t_pointd world)
{
	t_pointd mini;

	// offset relative to player
	double rel_x = world.x - cub->p.pos.x;
	double rel_y = world.y - cub->p.pos.y;

	// scale from world units to minimap pixels
	mini.x = (MINIMAP_SIZE / 2) + rel_x;
	mini.y = (MINIMAP_SIZE / 2) + rel_y;

	return mini;
}

// void	draw_ceiling_and_floor(t_cub *cub)
// {
// 	// Draw floor
// 	for (int y = 0; y < cub->half_height; ++y)
// 		for (int x = 0; x < WIDTH - 1; x++)
// 			put_pixel(cub, x, y, 0x0099ff); // Light blue ceiling

// 	// Draw ceiling 
//     for (int y = cub->half_height; y < HEIGHT - 1; ++y)
// 		for (int x = 0; x < WIDTH - 1; x++)
// 			put_pixel(cub, x, y, 0x005500); // Dark grey floor
// }

void	draw_line_to(t_cub *cub, t_pointd from, t_pointd to, int color)
{
	int			i;
	double		steps;
	t_pointd	dist;
	t_pointd	inc;
	t_pointd	start;

	i = 0;
	dist.x = to.x - from.x;
	dist.y = to.y - from.y;
	steps = fmax(fabs(dist.x), fabs(dist.y));
	inc.x = dist.x / steps;
	inc.y = dist.y / steps;
	start.x = from.x;
	start.y = from.y;
	while (i <= steps)
	{
		put_pixel(cub, (int)start.x, (int)start.y, color);
		start.x += inc.x;
		start.y += inc.y;
		i++;
	}
}

//? Default draw_map
// void	draw_map(t_cub *cub)
// {
// 	t_pointi	pos;
// 	int			color;

// 	pos.y = 0;
// 	while (pos.y < MAP_HEIGHT)
// 	{
// 		pos.x = 0;
// 		while (pos.x < MAP_WIDTH)
// 		{
// 			if (cub->map.array[pos.y][pos.x] == 1)
// 				color = 0xffffff;
// 			else
// 				color = 0x000000;
// 			draw_square(cub, pos.x * BLOCK_SIZE, pos.y * BLOCK_SIZE, BLOCK_SIZE, color);
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// }
