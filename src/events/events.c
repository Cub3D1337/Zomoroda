/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:31 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/25 16:47:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int loading(t_cub *cub)
{
	printf("Loading\n");
	cub->intro.intro_index = 0;
	cub->intro.intro_done = false;
	cub->intro.last_time = 0;
	if (cub->flag == LAODING_1)
	{
		cub->intro.logo_path = "./textures/zomoroda/logo.xpm";
		cub->intro.intro_path = "./textures/zomoroda/intro/";
		cub->intro.door_path = "./textures/zomoroda/door.xpm";
		cub->intro.bear_path = "./textures/zomoroda/animation/bear/";
		cub->intro.bear_click_path = "./textures/zomoroda/animation/bear_click/";
	}
	// else
	// 	cub->intro.logo_path = "./textures/action/logo.xpm";
	// 	cub->intro.intro_path = "./textures/action/intro/";
	// 	cub->intro.door_path = "./textures/action/door.xpm";
	if (put_logo(cub))
		return (EXIT_FAILURE);
	if (load_textures(cub))
		return (EXIT_FAILURE);
	play_music(0);
	cub->flag = INTRO;
	return (EXIT_SUCCESS);
}

static int	menu(t_cub *cub)
{
	printf("Menu\n");
	// cub->intro.door_path = "./textures/door.xpm";
	// if (put_logo(cub))
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_loop_hook(t_cub *cub)
{
	double	current;
	double	frame_time;

	if (cub->flag == MENU)
		menu(cub);
	else if (cub->flag == LAODING_1 || cub->flag == LAODING_2)
		loading(cub);
	else if (cub->flag == INTRO)
	{
		if (put_intro(cub) == EXIT_FAILURE)
		{
			stop_music();
			play_music(1);
			cub->flag = RENDER;
		}
	}
	else
	{
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
	}		
	return (EXIT_SUCCESS);
}

int	mouse_hook(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		cub->obj.frame = 0;
		cub->obj.inspect = true;
	}
	if (button == 3)
		cub->track_mouse = !cub->track_mouse;
	return (0);
}

void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, ON_KEYDOWN, KeyPressMask, ft_key_press, cub);
	mlx_hook(cub->mlx_win, ON_KEYUP, KeyReleaseMask, ft_key_release, cub);
	mlx_hook(cub->mlx_win, ON_DESTROY, DestroyNotifyMask, ft_exit, cub);
	mlx_hook(cub->mlx_win, ON_MOUSE_MOVE, PointerMotionMask,
		ft_mouse_move, cub);
	mlx_mouse_hook(cub->mlx_win, mouse_hook, cub);
	mlx_loop_hook(cub->mlx, ft_loop_hook, cub);
}
