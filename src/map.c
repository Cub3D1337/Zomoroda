/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:35:11 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/20 21:35:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_map_square(t_cub *cub, int x, int y, int size, int color)
{
	t_pointi		incr_pos;
	unsigned int	*pixels;
	unsigned int	pitch;

	incr_pos.y = 0;
	pixels = (unsigned int *) cub->map_img.img_pixels_ptr;
	pitch = cub->map_img.line_length / sizeof(unsigned int);
	while (incr_pos.y < size)
	{
		incr_pos.x = 0;
		while (incr_pos.x < size)
		{
			if (!(x < 0 || x >= cub->map.map_width || y < 0 
				|| y >= cub->map.map_height))
				pixels[(y + incr_pos.y) * pitch + (x + incr_pos.x)] = color;
			incr_pos.x++;
		}
		incr_pos.y++;
	}
}

void	draw_init_map(t_cub *cub)
{
	t_pointi	pos;
	int			color;

	ft_memset(cub->map_img.img_pixels_ptr, 0,
		cub->map.map_height * cub->map_img.line_length);
	pos.y = 0;
	while (pos.y < MAP_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < MAP_WIDTH)
		{
			if (cub->map.array[pos.y][pos.x] == 1)
				color = 0xffffff;
			else
				color = 0x333333;
			//TODO: begin from + (MINIMAP_SIZE / 2)
			draw_map_square(cub, cub->map.padding + pos.x * BLOCK_SIZE,
			cub->map.padding + pos.y * BLOCK_SIZE, BLOCK_SIZE, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_map0(t_cub *cub)
{
	t_pointi	pos;
	int			color;
	unsigned int	*pixels;
	unsigned int	pitch;

	pixels = (unsigned int *) cub->map_img.img_pixels_ptr;
	pitch = cub->map_img.line_length / sizeof(unsigned int);	

	pos.y = 0;
	while (pos.y < cub->map.map_height)
	{
		pos.x = 0;
		while (pos.x < cub->map.map_width)
		{
			color = pixels[(int)pos.y * pitch + (int)pos.x];
			put_pixel(cub, pos.x, pos.y, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_map(t_cub *cub)
{
	t_map_ctx		ctx;
	t_pointi		pos;
	t_pointi		cord;
	int				color;
	
	ctx.pixels = (unsigned int *) cub->map_img.img_pixels_ptr;
	ctx.pitch = cub->map_img.line_length / sizeof(unsigned int);
	
	ctx.norm_ply_pos.x = cub->p.pos.x + cub->map.padding;
	ctx.norm_ply_pos.y = cub->p.pos.y + cub->map.padding;

	ctx.start.x = ctx.norm_ply_pos.x - cub->map.padding;
	ctx.end.x = ctx.norm_ply_pos.x + cub->map.padding;
	
	ctx.start.y = ctx.norm_ply_pos.y - cub->map.padding;
	ctx.end.y = ctx.norm_ply_pos.y + cub->map.padding;

	ctx.rows.x = (int)(ctx.end.x - ctx.start.x + 0.5);
	ctx.rows.y = (int)(ctx.end.y - ctx.start.y + 0.5);

	pos.y = 0;
	while (pos.y < ctx.rows.y)
	{
		pos.x = 0;
		while (pos.x < ctx.rows.x)
		{
			cord.x = (int)ctx.start.x + pos.x;
            cord.y = (int)ctx.start.y + pos.y;
			
			color = ctx.pixels[cord.y * ctx.pitch + cord.x];
			put_pixel(cub, pos.x, pos.y, color);
			pos.x++;
		}
		pos.y++;
	}
}
