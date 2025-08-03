/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:41:46 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/03 15:16:23 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate(t_cub *cub)
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
	if (cub->p.angle < 0)
		cub->p.angle += 2 * M_PI;
	if (cub->p.angle >= 2 * M_PI)
		cub->p.angle -= 2 * M_PI;
}

void reset_player(t_cub *cub)
{
	draw_square(cub, cub->p.prev_x - (cub->p.half), cub->p.prev_y - (cub->p.half), cub->p.size, 0x000000);
	// TODO: the detailed implementation
	// t_pointi	incr_pos;
	// t_pointi	norm_pos;

	// norm_pos.y = (int)cub->p.prev_y - (cub->p.half);
	// norm_pos.x = (int)cub->p.prev_x - (cub->p.half);
	// incr_pos.y = 0;
	// while (incr_pos.y < cub->p.size)
	// {
	// 	incr_pos.x = 0;
	// 	while (incr_pos.x < cub->p.size)
	// 	{
	// 		put_pixel(cub, (norm_pos.x + incr_pos.x),
	// 			(norm_pos.y + incr_pos.y), 0x000000);
	// 		incr_pos.x++;
	// 	}
	// 	incr_pos.y++;
	// }
}

t_bool	check_boundaries(t_cub *cub)
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

void	move_with_steps(t_cub *cub, t_pointd delta)
{
	double		step;
	double		len;
	int			steps;
	t_pointd	delta_steps;
	
	step = 0.5;
	len = sqrt(delta.x * delta.x + delta.y * delta.y);
	steps = len / step;
	delta_steps.x = delta.x / steps;
	delta_steps.y = delta.y / steps;
	if (steps == 0)
		steps = 1;
	while (steps--)
	{
		cub->p.x += delta_steps.x;
		cub->p.y += delta_steps.y;
		if (!check_boundaries(cub))
		{
			cub->p.x -= delta_steps.x;
			cub->p.y -= delta_steps.y;
			break;
		}
	}
}

void move(t_cub *cub)
{
	double		speed;
	t_pointd	delta;

	if (cub->p.rotate_left || cub->p.rotate_right)
	{	
		rotate(cub);
	}
	if (cub->p.move_up || cub->p.move_down
		|| cub->p.move_left || cub->p.move_right)
	{
		// Save previous position BEFORE moving
		cub->p.prev_y = cub->p.y;
		cub->p.prev_x = cub->p.x;
		delta.x = 0;
		delta.y = 0;
		speed = SPEED * cub->delta_time;

		// if (cub->p.move_up)
		// 	delta.y -= speed;
		// if (cub->p.move_down)
		// 	delta.y += speed;
		// if (cub->p.move_left)
		// 	delta.x -= speed;
		// if (cub->p.move_right)
		// 	delta.x += speed;

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

		// Reset the square at previous position
		reset_player(cub); // NOW this will use prev_x / prev_y
	}
}
