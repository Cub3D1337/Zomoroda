/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:41:46 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	rotate(t_cub *cub)
{
	if (cub->p.rotate_left)
	{
		cub->p.angle -= ROT_SPEED;
	}
	else if (cub->p.rotate_right)
	{
		cub->p.angle += ROT_SPEED;
	}
	//TODO: You need to understand the Normalize angle to 0 ~ 2π
	//? So now the angle is always in the valid range [0, 2π).
	if (cub->p.angle < 0)
		cub->p.angle += 2 * M_PI;
	if (cub->p.angle >= 2 * M_PI)
		cub->p.angle -= 2 * M_PI;
}

static t_bool	check_boundaries(t_cub *cub)
{
	t_pointi	ply_corners[4];
	int			i;

	if ((int)cub->p.x - cub->p.half < 0
		||(int) cub->p.x + cub->p.half >= (MAP_WIDTH * MAP_SIZE) + 1
		|| (int)cub->p.y - cub->p.half < 0
		|| (int)cub->p.y + cub->p.half >= (MAP_HEIGHT * MAP_SIZE) + 1)
		return (false);
	// Check actual corners of the square (in tile units)
	ply_corners[0].x = (cub->p.x - cub->p.half) / MAP_SIZE; // Top-Left
	ply_corners[0].y = (cub->p.y - cub->p.half) / MAP_SIZE;
	ply_corners[1].x = (cub->p.x + cub->p.half - 1) / MAP_SIZE; // Top-Right
	ply_corners[1].y = (cub->p.y - cub->p.half) / MAP_SIZE;
	ply_corners[2].x = (cub->p.x - cub->p.half) / MAP_SIZE; // Bottom-Left
	ply_corners[2].y = (cub->p.y + cub->p.half - 1) / MAP_SIZE;
	ply_corners[3].x = (cub->p.x + cub->p.half - 1) / MAP_SIZE; // Bottom-Right
	ply_corners[3].y = (cub->p.y + cub->p.half - 1) / MAP_SIZE;
	i = 0;
	while (i < 4)
	{	
		if (cub->map.array[ply_corners[i].y][ply_corners[i].x] == 1)
			return (false);
		i++;
	}
	return (true);
}

static void	move_with_steps(t_cub *cub, t_pointd delta)
{
	double		step = 0.5;
	double		len = sqrt(delta.x * delta.x + delta.y * delta.y);
	int			steps = (int)(len / step);
	t_pointd	delta_steps;

	if (steps <= 0)
		steps = 1;
	delta_steps.x = delta.x / steps;
	delta_steps.y = delta.y / steps;
	while (steps--)
	{
		// Try move X
		cub->p.x += delta_steps.x;
		if (!check_boundaries(cub))
			cub->p.x -= delta_steps.x;
		// Try move Y
		cub->p.y += delta_steps.y;
		if (!check_boundaries(cub))
			cub->p.y -= delta_steps.y;
	}
}

static void	update_position(t_cub *cub, t_pointd delta, double speed)
{
		//? The cos and sin give the percent of tilt for the x and y axis
		//? so this percent for eaxh side is mulipated by speed (conclusion: we get the speed for each axe)
		//? we get the full angle because this is the player view angle
		if (cub->p.move_up)
		{
			delta.x += cos(cub->p.angle) * speed;
			delta.y += sin(cub->p.angle) * speed;
		}
		if (cub->p.move_down)
		{
			delta.x -= cos(cub->p.angle) * speed;
			delta.y -= sin(cub->p.angle) * speed;
		}
		//? We get the (full angle -+ quadrant) because this is the player left and right edges
		//? same mvt applyed for those edges
		if (cub->p.move_left)
		{
			delta.x += cos(cub->p.angle - M_PI_2) * speed;
			delta.y += sin(cub->p.angle - M_PI_2) * speed;
		}
		if (cub->p.move_right)
		{
			delta.x += cos(cub->p.angle + M_PI_2) * speed;
			delta.y += sin(cub->p.angle + M_PI_2) * speed;
		}
		if (delta.x != 0 || delta.y != 0)
			move_with_steps(cub, delta);
}


void move(t_cub *cub)
{
	t_pointd	delta;
	double		speed;

	if (cub->p.rotate_left || cub->p.rotate_right)
		rotate(cub);
	if (cub->p.move_up || cub->p.move_down
		|| cub->p.move_left || cub->p.move_right)
	{
		cub->p.prev_y = cub->p.y;
		cub->p.prev_x = cub->p.x;
		delta.x = 0.0;
		delta.y = 0.0;
		speed = SPEED * cub->delta_time;
		update_position(cub, delta, speed);
	}
}
