/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:31 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/30 15:42:09 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_loop_hook(t_cub *cub)
{
	double	current;
	double	frame_time;

	current = get_time_ms();
	frame_time = current - cub->fps.last_frame_time;
	if (frame_time < cub->fps.frame_duration)
		return (EXIT_SUCCESS);
	cub->fps.delta_time = frame_time / 1000.0;
	cub->fps.last_frame_time = current;
	cub->fps.frames++;
	if (current - cub->fps.last_time >= 1000.0)
	{
		cub->fps.fps = cub->fps.frames;
		cub->fps.frames = 0;
		cub->fps.last_time = current;
	}
	mouse_handler(cub);
	move(cub);
	render(cub);
	return (EXIT_SUCCESS);
}

// TODO: On mouse IN / On Mouse OUT
void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, ON_KEYDOWN, KeyPressMask, ft_key_press, cub);
	mlx_hook(cub->mlx_win, ON_KEYUP, KeyReleaseMask, ft_key_release, cub);
	mlx_hook(cub->mlx_win, ON_DESTROY, DestroyNotifyMask, ft_exit, cub);
	mlx_mouse_hide(cub->mlx, cub->mlx_win);
	mlx_hook(cub->mlx_win, ON_MOUSEMOVE, PointerMotionMask, ft_mouse_move, cub);
	mlx_loop_hook(cub->mlx, ft_loop_hook, cub);
}
