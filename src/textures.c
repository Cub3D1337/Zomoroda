/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:48:21 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/12 17:05:59 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void set_texture_paths(t_cub *cub)
{
	cub->textures[0].relative_path = "./textures/wall.xpm"; // Simple wall
	cub->textures[0].img_width = 64;
	cub->textures[0].img_height = 64;

	// cub->textures[0].relative_path = "./textures/north.xpm"; // North wall
	// cub->textures[1].relative_path = "./textures/south.xpm"; // South wall
	// cub->textures[2].relative_path = "./textures/east.xpm";  // East wall
	// cub->textures[3].relative_path = "./textures/west.xpm";  // West wall
}

int get_texel(t_img_texture *texture, int x, int y)
{
	if (!texture || !texture->img_pixels_ptr)
		return (0); // fallback color or error

	// Prevent reading outside texture bounds
	if (x < 0 || x >= texture->img_width || y < 0 || y >= texture->img_height)
		return (0); // black or fallback

	char *pixel = texture->img_pixels_ptr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	return *(unsigned int *)pixel;
}

void mapping_textures(
	t_cub *cub, t_pointd ray_dir, t_dda_result result,
	int x, double line_height, int start_y, int end_y)
{
	t_texture_data	data;
	
	data.tex = &cub->textures[0];
	// 1) Use exact hit position from DDA (avoids compression artifacts)
	if (result.side == HORIZONTAL)
		data.wallX = result.hit_point.y / MAP_SIZE;
	else
		data.wallX = result.hit_point.x / MAP_SIZE;
	data.wallX -= floor(data.wallX); // fractional part only
	// 2) Texture column index
	data.tex_cord.x = (int)(data.wallX * data.tex->img_width);
	if ((result.side == HORIZONTAL && ray_dir.x > 0) ||
		(result.side == VERTICAL && ray_dir.y < 0))
	{
		data.tex_cord.x = data.tex->img_width - data.tex_cord.x - 1;
	}
	// 3) Step: how much to move in texture for each screen pixel
	data.step = (double)data.tex->img_height / line_height;
	// 4) Initial texture y position
	// We start drawing partway into the texture, because the top part of the wall is off-screen.
	data.tex_pos = (start_y - HEIGHT / 2.0 + line_height / 2.0) * data.step;
	// 5) Draw vertical stripe
	while (start_y <= end_y)
	{
		data.tex_cord.y = (int)data.tex_pos;
		if (data.tex_cord.y < 0) data.tex_cord.y = 0;
		if (data.tex_cord.y >= data.tex->img_height) data.tex_cord.y = data.tex->img_height - 1;

		data.color = get_texel(data.tex, data.tex_cord.x, data.tex_cord.y);
		if (check_minimap_edge(x, start_y))
			put_pixel(cub, x, start_y, data.color);
		data.tex_pos += data.step;
		start_y++;
	}
}
