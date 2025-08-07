/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:08:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/06 18:09:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	check_wall_hit(t_cub *cub, int x, int y)
{
	if (cub->map.array[y / MAP_SIZE][x / MAP_SIZE] == 1)
		return (true);
	return (false);
}

t_bool	check_minimap_edge(int x, int y)
{
	if (x >= MAP_WIDTH * MAP_SIZE
		|| y >= MAP_HEIGHT * MAP_SIZE)
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
	int				y;

	ray_dir.x = cos(ray_angle);
	ray_dir.y = sin(ray_angle);
	dda(cub, ray_dir, &result);
	line_height = MAP_SIZE / result.dist * (WIDTH / 2);
	if (line_height > HEIGHT)
    	line_height = HEIGHT;
	// The draw begin from to of window to bottom you see this because we increase y++,
	// That's mean the window's top y = 0 and bottom y = HEIGHT
	start_y = (HEIGHT - line_height) / 2;
	end_y = start_y + line_height;
	y = start_y;
	// Walls
	while (y < end_y)
	{
		if (check_minimap_edge(x, y))
			put_pixel(cub, x, y, 0xff5500);
		y++;
	}
	// Floor
	while (end_y < HEIGHT)
	{
		if (check_minimap_edge(x, end_y))
			put_pixel(cub, x, end_y, 0x222222);
		end_y++;
	}
	// Sky
	while (start_y > 0)
	{
		if (check_minimap_edge(x, start_y))
			put_pixel(cub, x, start_y, 0x0099ff);
		start_y--;
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
