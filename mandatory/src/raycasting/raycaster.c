/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:08:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/26 22:31:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ray(t_cub *cub, int x, double ray_angle)
{
	t_ray_ctx	ctx;

	ctx.x = x;
	ctx.ray_dir.x = cos(ray_angle);
	ctx.ray_dir.y = sin(ray_angle);
	dda(cub, ctx.ray_dir, &ctx.result);
	ctx.perp_dist = ctx.result.dist * cos(ray_angle - cub->p.angle);
	ctx.line_height = (BLOCK_SIZE / ctx.perp_dist) * cub->projection_plane;
	ctx.start_y = cub->half_height - (int)(ctx.line_height / 2)
		+ (int)cub->p.pitch;
	if (ctx.start_y < 0)
		ctx.start_y = 0;
	ctx.end_y = cub->half_height + (int)(ctx.line_height / 2)
		+ (int)cub->p.pitch;
	if (ctx.end_y >= HEIGHT)
		ctx.end_y = HEIGHT - 1;
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
