/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:31 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/23 16:31:22 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	apply_mouse_rotation(t_cub *cub)
{
	t_pointd	delta;

	// Compute mouse delta relative to screen center
	delta.x = cub->mouse.x - cub->half_width;
	delta.y = cub->mouse.y - cub->half_height;

	// Update angle and pitch only once per frame if mouse position ischanged
	if (delta.x == 0 && delta.y == 0)
		return ;
	if (delta.x != 0)
	{
		cub->p.angle += delta.x * YAW_SENSITIVITY;
		if (cub->p.angle < 0)
			cub->p.angle += 2 * M_PI;
		if (cub->p.angle >= 2 * M_PI)
			cub->p.angle -= 2 * M_PI;

		cub->p.cosA = cos(cub->p.angle);
		cub->p.sinA = sin(cub->p.angle);
	}
	// Update pitch (up/down)
	if (delta.y != 0)
	{
		cub->p.pitch -= delta.y * PITCH_SENSITIVITY; // invert so mouse up looks up
		if (cub->p.pitch > MAX_PITCH) 
			cub->p.pitch = MAX_PITCH;
		if (cub->p.pitch < MIN_PITCH) 
			cub->p.pitch = MIN_PITCH;
		cub->p.horizon = (cub->half_height) + (int)cub->p.pitch;
	}
	// // Re-center mouse to avoid hitting screen edge
	mlx_mouse_move(cub->mlx, cub->mlx_win, cub->half_width, cub->half_height);
	cub->mouse.x = cub->half_width;
	cub->mouse.y = cub->half_height;
}

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
		cub->last_time = current;
	}
	apply_mouse_rotation(cub);
	move(cub);
	draw(cub);
	// printf("Render call in %.2g ms\n", get_time_ms() - current);
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
	if (keycode == UP_KEY)
		cub->p.rotate_up = true;
	if (keycode == DOWN_KEY)
		cub->p.rotate_down = true;
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
	if (keycode == UP_KEY)
		cub->p.rotate_up = false;
	if (keycode == DOWN_KEY)
		cub->p.rotate_down = false;
	return (EXIT_SUCCESS);
}

int	ft_mouse_move(int x, int y, t_cub *cub)
{
	// Just store mouse pos, don’t apply rotation here
	cub->mouse.x = x;
	cub->mouse.y = y;
	return (EXIT_SUCCESS);
}

void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, ON_KEYDOWN, KeyPressMask, ft_key_press, cub);
	mlx_hook(cub->mlx_win, ON_KEYUP, KeyReleaseMask, ft_key_release, cub);
	mlx_hook(cub->mlx_win, ON_MOUSEMOVE, PointerMotionMask, ft_mouse_move, cub);
	mlx_hook(cub->mlx_win, ON_DESTROY, DestroyNotifyMask, ft_exit, cub);
	mlx_loop_hook(cub->mlx, ft_loop_hook, cub);
}
