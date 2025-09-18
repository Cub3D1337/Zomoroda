/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:08:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/05 16:38:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void draw_ray(t_cub *cub, int x, double ray_angle)
{
	t_pointd     ray_dir;
	t_dda_result	result;
	double       perp_dist;
	double       line_height;
	int          start_y;
	int				end_y;
	t_tex_ctx		ctx;		

	// Ray direction
	ray_dir.x = cos(ray_angle);
	ray_dir.y = sin(ray_angle);

	// Perform DDA
	dda(cub, ray_dir, &result);

	// --- IMPORTANT FIX ---
	// Convert "hit distance" into perpendicular distance to projection plane
	// This removes the fisheye and keeps texture scale constant
	perp_dist = result.dist * cos(ray_angle - cub->p.angle);

	// Wall height in screen space
	line_height = (BLOCK_SIZE / perp_dist) * cub->projection_plane;

	// Clamp values
	start_y = cub->half_height - (int)(line_height / 2) + (int)cub->p.pitch;
	if (start_y < 0)
		start_y = 0;
	end_y = cub->half_height + (int)(line_height / 2) + (int)cub->p.pitch;
	if (end_y >= HEIGHT)
		end_y = HEIGHT - 1;

	// Draw the textured wall column
	ctx = (t_tex_ctx){ray_dir, result, x, line_height, start_y, end_y};
	mapping_textures(cub, &ctx);
}

void	raycasting(t_cub *cub)
{
	double	ray_angle;
	double	angle_step;
	int		x;

	x = 0;
	ray_angle = cub->p.angle - (cub->fov / 2);
	angle_step = cub->fov / WIDTH;
	while (x < WIDTH)
	{
		draw_ray(cub, x, ray_angle);
		ray_angle += angle_step;
		x++;
	}
}
