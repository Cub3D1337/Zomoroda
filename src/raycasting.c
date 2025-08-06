/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:08:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/06 11:19:11 by abnsila          ###   ########.fr       */
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
	t_pointd		ray_dir;
	t_dda_result	result;
	double			line_height;
	int				start_y;
	int				end_y;

	ray_dir.x = cos(ray_angle);
	ray_dir.y = sin(ray_angle);
	dda(cub, ray_dir, &result);
	line_height = MAP_SIZE / result.dist * (WIDTH / 2);
	if (line_height > HEIGHT)
    	line_height = HEIGHT;
	start_y = (HEIGHT - line_height) / 2;
	end_y = start_y + line_height;
	while (start_y < end_y)
	{
		put_pixel(cub, x, start_y, 0x0000ff);
		start_y++;
	}
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
		draw_ray(cub, x, ray_angle);
		ray_angle += angle_step;
		x++;
	}
}
