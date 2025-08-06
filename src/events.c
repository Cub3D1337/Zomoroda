/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:31 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/06 10:51:35 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int ft_loop_hook(t_cub *cub)
{
	double current;
	double frame_time;

	current = get_time_ms(); // return double ms
	frame_time = current - cub->last_frame_time;

	if (frame_time < FRAME_DURATION)
		return (EXIT_SUCCESS);  // Too soon, wait

	cub->delta_time = frame_time / 1000.0;
	cub->last_frame_time = current;

	cub->frames++;
	if (current - cub->last_time >= 1000.0)
	{
		cub->fps = cub->frames;
		cub->frames = 0;
		cub->last_time += current;  // accumulate instead of = current

		// I need to call the fps fuction every frame
	}
	// printf("FPS: %d\n", cub->fps);
	move(cub);
	draw(cub);
	return (EXIT_SUCCESS);
}

static int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == ESCAPE_KEY)
		ft_exit(cub);
	else if (keycode == W_KEY)
		cub->p.move_up = true;
	else if (keycode == S_KEY)
		cub->p.move_down = true;
    else if (keycode == A_KEY)
		cub->p.move_left = true;
	else if (keycode == D_KEY)
	    cub->p.move_right = true;

	if (keycode == LEFT_KEY)
		cub->p.rotate_left = true;
	if (keycode == RIGHT_KEY)
	cub->p.rotate_right = true;
	return (EXIT_SUCCESS);
}

static int	ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == W_KEY)
		cub->p.move_up = false;
	else if (keycode == S_KEY)
		cub->p.move_down = false;
    else if (keycode == A_KEY)
		cub->p.move_left = false;
	else if (keycode == D_KEY)
		cub->p.move_right = false;
        
	if (keycode == LEFT_KEY)
		cub->p.rotate_left = false;
	if (keycode == RIGHT_KEY)
		cub->p.rotate_right = false;
	return (EXIT_SUCCESS);
}

void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, ON_KEYDOWN, KeyPressMask, ft_key_press, cub);
	mlx_hook(cub->mlx_win, ON_KEYUP, KeyReleaseMask, ft_key_release, cub);
	mlx_hook(cub->mlx_win, ON_DESTROY, DestroyNotifyMask, ft_exit, cub);
	mlx_loop_hook(cub->mlx, ft_loop_hook, cub);
}
