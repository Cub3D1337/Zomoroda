/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:31 by hwahmane          #+#    #+#             */
/*   Updated: 2025/07/28 13:49:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// TODO: Limit FPS
// TODO: Try to create a copy of the buffer image with the minimap only

int ft_loop_hook(t_cub *cub)
{
	time_t current;
	time_t frame_time;
	
	current = get_time_ms();
	frame_time = current - cub->last_frame_time;

	if (frame_time < FRAME_DURATION)
		return (EXIT_SUCCESS);  // Too soon, wait

	cub->delta_time = (current - cub->last_frame_time) / 1000.0;
	cub->last_frame_time = current;

	cub->frames++;
	if (current - cub->last_time >= 1000.0)
	{
		cub->fps = cub->frames;
		cub->frames = 0;
		cub->last_time = current;
		printf("FPS: %d\n", cub->fps);
	}

	move(cub);
	return (EXIT_SUCCESS);
}


// int ft_loop_hook(t_cub *cub)
// {
// 	double	current;

// 	if (!cub || !cub->img.img_ptr)
// 		ft_exit(cub);
// 	// Increment frame
// 	current = get_time_ms();  // ms

// 	cub->delta_time = (current - cub->last_frame_time) / 1000.0;
// 	cub->last_frame_time = current;

// 	// FPS display update every 1s
// 	cub->frames++;
// 	if (current - cub->last_time >= 1000.0)
// 	{
// 		cub->fps = cub->frames;
// 		cub->frames = 0;
// 		cub->last_time = current;
// 		printf("FPS: %d\n", cub->fps);
// 	}
//     move(cub);
// 	return (EXIT_SUCCESS);
// }

int	ft_key_press(int keycode, t_cub *cub)
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

	// else if (keycode == A_KEY)
	// 	cub->p.rotate_left = true;
	// else if (keycode == D_KEY)
	// cub->p.rotate_right = true;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == W_KEY)
		cub->p.move_up = false;
	else if (keycode == S_KEY)
		cub->p.move_down = false;
    else if (keycode == A_KEY)
		cub->p.move_left = false;
	else if (keycode == D_KEY)
		cub->p.move_right = false;
        
	// else if (keycode == A_KEY)
	// 	cub->p.rotate_left = false;
	// else if (keycode == D_KEY)
	// 	cub->p.rotate_right = false;
	return (EXIT_SUCCESS);
}

void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, ON_KEYDOWN, KeyPressMask, ft_key_press, cub);
	mlx_hook(cub->mlx_win, ON_KEYUP, KeyReleaseMask, ft_key_release, cub);
	// mlx_hook(cub->mlx_win, ON_DESTROY, DestroyNotifyMask, ft_exit, cub);
	mlx_loop_hook(cub->mlx, ft_loop_hook, cub);
}
