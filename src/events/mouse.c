/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:27:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/08 11:21:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	apply_mouse_rotation(t_cub *cub, t_pointd *delta)
{
	if (delta->x != 0)
	{
		cub->p.angle += delta->x * X_SENSITIVITY;
		if (cub->p.angle < 0)
			cub->p.angle += 2 * M_PI;
		if (cub->p.angle >= 2 * M_PI)
			cub->p.angle -= 2 * M_PI;
		cub->p.cosA = cos(cub->p.angle);
		cub->p.sinA = sin(cub->p.angle);
	}
	if (delta->y != 0)
	{
		cub->p.pitch -= delta->y * Y_SENSITIVITY;
		if (cub->p.pitch > MAX_PITCH)
			cub->p.pitch = MAX_PITCH;
		if (cub->p.pitch < MIN_PITCH)
			cub->p.pitch = MIN_PITCH;
		cub->p.horizon = (cub->half_height) + (int)cub->p.pitch;
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
	apply_mouse_rotation(cub, &delta);
}

int	ft_mouse_move(int x, int y, t_cub *cub)
{
	cub->mouse.x = x;
	cub->mouse.y = y;
	return (EXIT_SUCCESS);
}
