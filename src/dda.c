/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:18:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/06 17:09:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	setup_dir_step(t_dda *dda, t_pointd ray_dir)
{
	if (ray_dir.x < 0)
		dda->dir_step.x = -1;
	else
		dda->dir_step.x = 1;
	if (ray_dir.y < 0)
		dda->dir_step.y = -1;
	else
		dda->dir_step.y = 1;
}

void	setup_dda(t_cub *cub, t_dda *dda, t_pointd ray_dir)
{
	// Get player pos in grid map, the value truncate to int
	// Those values is modified after each jump to check collision with wall 
	dda->map_pos.x = (int)cub->p.pos.x / MAP_SIZE;
	dda->map_pos.y = (int)cub->p.pos.y / MAP_SIZE;
	// Grid jump step on x and y (Horizontal and Vertical)
	dda->grid_step.x = fabs(1 / ray_dir.x);
	dda->grid_step.y = fabs(1 / ray_dir.y);
	// Hit flag
	dda->hit = false;
	// Setup initial hypotenuse_dist (x, y) lenght to begin a simple and constant jump grid
	if (ray_dir.x < 0)
		dda->hypotenuse_dist.x = ((cub->p.pos.x / MAP_SIZE) - dda->map_pos.x) * dda->grid_step.x;
	else
		dda->hypotenuse_dist.x = ((dda->map_pos.x + 1) - (cub->p.pos.x / MAP_SIZE)) * dda->grid_step.x;
	if (ray_dir.y < 0)
		dda->hypotenuse_dist.y = ((cub->p.pos.y / MAP_SIZE) - dda->map_pos.y) * dda->grid_step.y;
	else
		dda->hypotenuse_dist.y = ((dda->map_pos.y + 1) - (cub->p.pos.y / MAP_SIZE)) * dda->grid_step.y;
	// Setup dir step
	setup_dir_step(dda, ray_dir);
}

void	compute_ray_lenght(t_cub *cub, t_dda *dda, t_pointd ray_dir, t_dda_result *result)
{
	//? Use the last side distance depending on hit side
	if (dda->side == HORIZONTAL)
	{
		result->dist = (dda->map_pos.x - (cub->p.pos.x / MAP_SIZE)
			+ (1 - dda->dir_step.x) / 2) / ray_dir.x;
	}
	else
	{		
		result->dist = (dda->map_pos.y - (cub->p.pos.y / MAP_SIZE)
			+ (1 - dda->dir_step.y) / 2) / ray_dir.y;
	}
	result->dist *= MAP_SIZE;
	//? Final position = Start position + Direction × Distance
	result->hit_point.x = cub->p.pos.x + (ray_dir.x * result->dist);
	result->hit_point.y = cub->p.pos.y + (ray_dir.y * result->dist);
	draw_line_to(cub, cub->p.pos, result->hit_point, 0x00FF00);
}

void	dda(t_cub *cub, t_pointd ray_dir, t_dda_result *result)
{
	t_dda	dda;

	setup_dda(cub, &dda, ray_dir);
	while (!dda.hit)
	{
		if (dda.hypotenuse_dist.x <= dda.hypotenuse_dist.y)
		{
			dda.hypotenuse_dist.x += dda.grid_step.x;
			dda.map_pos.x += dda.dir_step.x;
			dda.side = HORIZONTAL;
		}
		else
		{
			dda.hypotenuse_dist.y += dda.grid_step.y;
			dda.map_pos.y += dda.dir_step.y;	
			dda.side = VERTICAL;
		}
		if (cub->map.array[dda.map_pos.y][dda.map_pos.x] == 1)
			dda.hit = true;
	}
	compute_ray_lenght(cub, &dda, ray_dir, result);
	// draw_square(cub, result->hit_point.x - cub->p.half, result->hit_point.y - cub->p.half, 4, 0x0000FF);
}
