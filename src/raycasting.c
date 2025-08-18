/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:08:51 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/18 13:45:29 by abnsila          ###   ########.fr       */
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

void draw_ray(t_cub *cub, int x, double ray_angle)
{
    t_pointd     ray_dir;
    t_dda_result result;
    double       perp_dist;
    double       line_height;
    int          start_y;
    int          end_y;

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
    line_height = (MAP_SIZE / perp_dist) * cub->projection_plane;

    // Clamp values
    start_y = (HEIGHT / 2) - (int)(line_height / 2);
    if (start_y < 0)
        start_y = 0;
    end_y = (HEIGHT / 2) + (int)(line_height / 2);
    if (end_y >= HEIGHT)
        end_y = HEIGHT - 1;

    // Draw the textured wall column
    mapping_textures(cub, ray_dir, result, x, line_height, start_y, end_y);

    // Draw floor
    for (int y = end_y + 1; y < HEIGHT; ++y)
        if (check_minimap_edge(x, y))
            put_pixel(cub, x, y, 0x005500); // Dark grey floor

    // Draw sky
    for (int y = 0; y < start_y; ++y)
        if (check_minimap_edge(x, y))
            put_pixel(cub, x, y, 0x0099ff); // Light blue sky
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
