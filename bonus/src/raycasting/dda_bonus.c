/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:18:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 00:08:09 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	setup_dir_step(t_dda *dda, t_pointd ray_dir)
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
	dda->p_cell.x = cub->p.pos.x / BLOCK_SIZE;
	dda->p_cell.y = cub->p.pos.y / BLOCK_SIZE;
	dda->map_pos.x = (int)dda->p_cell.x;
	dda->map_pos.y = (int)dda->p_cell.y;
	dda->grid_step.x = fabs(1 / ray_dir.x);
	dda->grid_step.y = fabs(1 / ray_dir.y);
	if (ray_dir.x < 0)
		dda->hypotenuse_dist.x = ((dda->p_cell.x) - dda->map_pos.x)
			* dda->grid_step.x;
	else
		dda->hypotenuse_dist.x = ((dda->map_pos.x + 1) - (dda->p_cell.x))
			* dda->grid_step.x;
	if (ray_dir.y < 0)
		dda->hypotenuse_dist.y = ((dda->p_cell.y) - dda->map_pos.y)
			* dda->grid_step.y;
	else
		dda->hypotenuse_dist.y = ((dda->map_pos.y + 1) - (dda->p_cell.y))
			* dda->grid_step.y;
	setup_dir_step(dda, ray_dir);
}

static void	compute_ray_lenght(t_cub *cub, t_dda *dda,
	t_pointd ray_dir, t_dda_result *result)
{
	result->side = dda->side;
	result->dir_step = dda->dir_step;
	result->map_pos.x = dda->map_pos.x;
	result->map_pos.y = dda->map_pos.y;
	if (dda->side == HORIZONTAL)
	{
		result->dist = (dda->map_pos.x - (dda->p_cell.x)
				+ (1 - dda->dir_step.x) / 2) / ray_dir.x;
	}
	else
	{
		result->dist = (dda->map_pos.y - (dda->p_cell.y)
				+ (1 - dda->dir_step.y) / 2) / ray_dir.y;
	}
	result->dist *= BLOCK_SIZE;
	result->hit_point.x = cub->p.pos.x + (ray_dir.x * result->dist);
	result->hit_point.y = cub->p.pos.y + (ray_dir.y * result->dist);
}

void	dda(t_cub *cub, t_pointd ray_dir, t_dda_result *result)
{
	t_dda	dda;

	setup_dda(cub, &dda, ray_dir);
	while (true)
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
		if (dda.map_pos.x < 0 || dda.map_pos.x >= cub->map.w
			|| dda.map_pos.y < 0 || dda.map_pos.y >= cub->map.h)
			break ;
		if (cub->map.array[dda.map_pos.y][dda.map_pos.x] == '1'
			|| cub->map.array[dda.map_pos.y][dda.map_pos.x] == 'D')
			break ;
	}
	compute_ray_lenght(cub, &dda, ray_dir, result);
}
