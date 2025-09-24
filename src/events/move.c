/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:41:46 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/24 23:08:12 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	rotate_horizontal(t_cub *cub)
{
	double	rot_speed;

	if (cub->p.rotate_left || cub->p.rotate_right)
	{
		rot_speed = H_ROT_SPEED * cub->fps.delta_time;
		if (cub->p.rotate_left)
			cub->p.angle -= rot_speed;
		else if (cub->p.rotate_right)
			cub->p.angle += rot_speed;
		if (cub->p.angle < 0)
			cub->p.angle += 2 * M_PI;
		if (cub->p.angle >= 2 * M_PI)
			cub->p.angle -= 2 * M_PI;
		cub->p.cos_a = cos(cub->p.angle);
		cub->p.sin_a = sin(cub->p.angle);
	}
}

static void	rotate_vertical(t_cub *cub)
{
	double	rot_speed;

	if (cub->p.rotate_up || cub->p.rotate_down)
	{
		rot_speed = V_ROT_SPEED * cub->fps.delta_time;
		if (cub->p.rotate_up)
			cub->p.pitch += rot_speed;
		else if (cub->p.rotate_down)
			cub->p.pitch -= rot_speed;
		if (cub->p.pitch > MAX_PITCH)
			cub->p.pitch = MAX_PITCH;
		if (cub->p.pitch < MIN_PITCH)
			cub->p.pitch = MIN_PITCH;
		cub->p.horizon = (cub->half_height) + (int)cub->p.pitch;
	}
}

static void	move_with_steps(t_cub *cub, t_pointd *delta)
{
	double		len;
	int			steps;
	t_pointd	delta_steps;

	len = sqrt(delta->x * delta->x + delta->y * delta->y);
	steps = (int)(len / TINY_STEP);
	if (steps <= 0)
		steps = 1;
	delta_steps.x = delta->x / steps;
	delta_steps.y = delta->y / steps;
	while (steps--)
	{
		cub->p.pos.x += delta_steps.x;
		if (!check_boundaries(cub))
			cub->p.pos.x -= delta_steps.x;
		cub->p.pos.y += delta_steps.y;
		if (!check_boundaries(cub))
			cub->p.pos.y -= delta_steps.y;
	}
}

static void	update_position(t_cub *cub, t_pointd *delta, double speed)
{
	if (cub->p.move_up)
	{
		delta->x += cub->p.cos_a * speed;
		delta->y += cub->p.sin_a * speed;
		cub->obj.offset.y++;
	}
	if (cub->p.move_down)
	{
		delta->x -= cub->p.cos_a * speed;
		delta->y -= cub->p.sin_a * speed;
		cub->obj.offset.y--;
	}
	if (cub->p.move_left)
	{
		delta->x += cos(cub->p.angle - M_PI_2) * speed;
		delta->y += sin(cub->p.angle - M_PI_2) * speed;
		cub->obj.offset.x++;
	}
	if (cub->p.move_right)
	{
		delta->x += cos(cub->p.angle + M_PI_2) * speed;
		delta->y += sin(cub->p.angle + M_PI_2) * speed;
		cub->obj.offset.x--;
	}
}

void	move(t_cub *cub)
{
	t_pointd	delta;
	double		speed;

	if (cub->p.rotate_left || cub->p.rotate_right
		|| cub->p.rotate_up || cub->p.rotate_down)
	{
		rotate_horizontal(cub);
		rotate_vertical(cub);
	}
	if (cub->p.move_up || cub->p.move_down
		|| cub->p.move_left || cub->p.move_right)
	{
		delta = (t_pointd){0, 0};
		speed = SPEED * cub->fps.delta_time;
		update_position(cub, &delta, speed);
		if (delta.x != 0 || delta.y != 0)
			move_with_steps(cub, &delta);
	}
}
