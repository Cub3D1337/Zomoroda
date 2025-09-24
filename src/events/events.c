/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:31 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/24 16:19:29 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_mouse_enter(t_cub *cub)
{
	cub->track_mouse = true;
	// cub->mouse.x = x;
	// cub->mouse.y = y;
	printf("Mouse enter\n");
	return (EXIT_SUCCESS);
}

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

int	mouse_hook(int button, int x, int y, t_cub *cub)
{
	if (button == 1)
	{
		cub->obj.frame = 0;
		cub->obj.inspect = true;
	}
	else
		cub->obj.inspect = false;
	return (0);
}

// TODO: On mouse IN / On Mouse OUT
void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, ON_KEYDOWN, KeyPressMask, ft_key_press, cub);
	mlx_hook(cub->mlx_win, ON_KEYUP, KeyReleaseMask, ft_key_release, cub);
	mlx_hook(cub->mlx_win, ON_DESTROY, DestroyNotifyMask, ft_exit, cub);
	mlx_hook(cub->mlx_win, ON_MOUSE_MOVE, PointerMotionMask, ft_mouse_move, cub);
	mlx_hook(cub->mlx_win, ON_MOUSE_ENTER, EnterWindowMask, ft_mouse_enter, cub);
	mlx_mouse_hook(cub->mlx_win, mouse_hook, cub);
	mlx_loop_hook(cub->mlx, ft_loop_hook, cub);
}
