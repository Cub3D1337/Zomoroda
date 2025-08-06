/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:08:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/06 10:52:20 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	check_wall_hit(t_cub *cub, int x, int y)
{
	if (cub->map.array[y / MAP_SIZE][x / MAP_SIZE] == 1)
		return (true);
	return (false);
}	

void	draw_ray(t_cub *cub, int x, double ray_angle)
{
	t_pointd	ray_pos;
	t_pointd	ray_step;

	ray_pos.x = cub->p.pos.x;
	ray_pos.y = cub->p.pos.y;
	ray_step.x = cos(ray_angle) * 0.6;
	ray_step.y = sin(ray_angle) * 0.6;
	while (true)
	{
		if (check_wall_hit(cub, ray_pos.x, ray_pos.y))
			break ;
		put_pixel(cub, ray_pos.x, ray_pos.y, 0x00ff00);
		ray_pos.x += ray_step.x;
		ray_pos.y += ray_step.y;
	}
}

void	dda_draw_ray(t_cub *cub, int x, double ray_angle)
{
	t_pointd		ray_dir;
	t_dda_result	result;

	ray_dir.x = cos(ray_angle);
	ray_dir.y = sin(ray_angle);
	dda(cub, ray_dir, &result);
}

void	raycasting(t_cub *cub)
{
	double	ray_angle;
	double	angle_step;
	int		x;

	x = 0;
	ray_angle = cub->p.angle - (FOV / 2);
	angle_step = FOV / WIDTH;
	while (x < WIDTH)
	{
		// draw_ray(cub, x, ray_angle);
		dda_draw_ray(cub, x, ray_angle);
		ray_angle += angle_step;
		x++;
	}
}
