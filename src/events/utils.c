/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:48:20 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/25 23:58:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	check_boundaries(t_cub *cub)
{
	t_pointi	ply_corners[4];
	t_pointi	map;
	t_pointd	p;
	t_pointi	i_h;

	p = (t_pointd){cub->p.pos.x, cub->p.pos.y};
	i_h = (t_pointi){0, cub->p.half};
	if ((int)p.x - i_h.y < BLOCK_SIZE || (int)p.y - i_h.y < BLOCK_SIZE
		|| (int) p.x + i_h.y >= (cub->map.w * BLOCK_SIZE) + 1 - BLOCK_SIZE
		|| (int)p.y + i_h.y >= (cub->map.h * BLOCK_SIZE) + 1 - BLOCK_SIZE)
		return (false);
	ply_corners[0] = (t_pointi){(int)(p.x - i_h.y), (int)(p.y - i_h.y)};
	ply_corners[1] = (t_pointi){(int)(p.x + i_h.y - 1), (int)(p.y - i_h.y)};
	ply_corners[2] = (t_pointi){(int)(p.x - i_h.y), (int)(p.y + i_h.y - 1)};
	ply_corners[3] = (t_pointi){(int)(p.x + i_h.y - 1), (int)(p.y + i_h.y - 1)};
	while (i_h.x < 4)
	{
		map.x = ply_corners[i_h.x].x / BLOCK_SIZE;
		map.y = ply_corners[i_h.x].y / BLOCK_SIZE;
		if (cub->map.array[map.y][map.x] == '1'
		|| cub->map.array[map.y][map.x] == 'D')
			return (false);
		i_h.x++;
	}
	return (true);
}

int state_menu(t_cub *cub)
{
	if (!cub->logo_texture.img_ptr)
	{
		cub->intro.logo_path = "./textures/menu.xpm";
		if (put_logo(cub) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int state_loading(t_cub *cub)
{
	t_game_mode *mode = &cub->modes[cub->selected_mode];

	cub->intro.intro_index = 0;
	cub->intro.intro_done = false;
	cub->intro.last_time = 0;
	cub->intro.logo_path      = mode->logo_path;
	cub->intro.intro_path     = mode->intro_path;
	cub->intro.door_path      = mode->door_path;
	cub->intro.obj_path       = mode->obj_path;
	cub->intro.obj_click_path = mode->obj_click_path;
	ft_memset(cub->img.img_pixels_ptr, 0,
		HEIGHT * cub->img.line_length);
	if (put_logo(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_textures(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	play_music(cub, ONCE);
	cub->state = STATE_INTRO;
	return (EXIT_SUCCESS);
}

int	state_intro(t_cub *cub)
{
    put_intro(cub);
    if (cub->intro.intro_done)
    {
        stop_music();
        play_music(cub, LOOP);
        cub->state = STATE_RENDER;
    }
    return (EXIT_SUCCESS);
}

int state_render(t_cub *cub)
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
