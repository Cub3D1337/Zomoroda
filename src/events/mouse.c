/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:27:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 23:08:12 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	apply_mouse_rotation_x(t_cub *cub, t_pointd *delta)
{
	if (delta->x != 0)
	{
		cub->p.angle += delta->x * X_SENSITIVITY;
		if (cub->p.angle < 0)
			cub->p.angle += 2 * M_PI;
		if (cub->p.angle >= 2 * M_PI)
			cub->p.angle -= 2 * M_PI;
		cub->p.cos_a = cos(cub->p.angle);
		cub->p.sin_a = sin(cub->p.angle);
		cub->obj.offset.x += delta->x * 0.5;
		if (cub->obj.offset.x > GUN_OFFSET)
			cub->obj.offset.x = GUN_OFFSET;
		else if (cub->obj.offset.x < -GUN_OFFSET)
			cub->obj.offset.x = -GUN_OFFSET;
	}
}

static void	apply_mouse_rotation_y(t_cub *cub, t_pointd *delta)
{
	if (delta->y != 0)
	{
		cub->p.pitch -= delta->y * Y_SENSITIVITY;
		if (cub->p.pitch > MAX_PITCH)
			cub->p.pitch = MAX_PITCH;
		if (cub->p.pitch < MIN_PITCH)
			cub->p.pitch = MIN_PITCH;
		cub->p.horizon = (cub->half_height) + (int)cub->p.pitch;
		cub->obj.offset.y += delta->y * 0.5;
		if (cub->obj.offset.y > GUN_OFFSET)
			cub->obj.offset.y = GUN_OFFSET;
		else if (cub->obj.offset.y < -GUN_OFFSET)
			cub->obj.offset.y = -GUN_OFFSET;
	}
}

void	mouse_handler(t_cub *cub)
{
	t_pointd	delta;

	if (cub->track_mouse == false)
		return ;
	delta.x = cub->mouse.x - cub->half_width;
	delta.y = cub->mouse.y - cub->half_height;
	if (delta.x == 0 && delta.y == 0)
		return ;
	mlx_mouse_move(cub->mlx, cub->mlx_win, cub->half_width, cub->half_height);
	cub->mouse.x = cub->half_width;
	cub->mouse.y = cub->half_height;
	apply_mouse_rotation_x(cub, &delta);
	apply_mouse_rotation_y(cub, &delta);
}

int	ft_mouse_move(int x, int y, t_cub *cub)
{
	cub->mouse.x = x;
	cub->mouse.y = y;
	return (EXIT_SUCCESS);
}
