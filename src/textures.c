/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:48:21 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/07 13:37:05 by abnsila          ###   ########.fr       */
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

void	mapping_textures(t_cub *cub, t_pointd ray_dir, t_dda_result result,
	int x, double line_height, int start_y, int end_y)
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;

	// 1. Calculate where the wall was hit (fractional X on wall tile)
	if (result.side == HORIZONTAL)
		wall_x = cub->p.pos.y + result.dist * ray_dir.y;
	else
		wall_x = cub->p.pos.x + result.dist * ray_dir.x;
	wall_x -= floor(wall_x);

	// 2. Convert wall_x to texture x coordinate
	tex_x = (int)(wall_x * cub->textures[0].img_width);
	if ((result.side == HORIZONTAL && ray_dir.x > 0) ||
		(result.side == VERTICAL && ray_dir.y < 0))
		tex_x = cub->textures[0].img_width - tex_x - 1;

	// 3. Calculate step and starting texture y coordinate
	step = (double)cub->textures[0].img_height / line_height;
	tex_pos = (start_y - HEIGHT / 2 + line_height / 2) * step;

	for (int y = start_y; y < end_y; y++)
	{
		int tex_y = (int)tex_pos & (cub->textures[0].img_height - 1);
		tex_pos += step;

		int color = get_texel(&cub->textures[0], tex_x, tex_y);
		put_pixel(cub, x, y, color);
	}
}

