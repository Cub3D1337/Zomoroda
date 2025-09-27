/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:56:26 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/27 08:52:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_default_values(t_cub *cub)
{
	cub->half_height = HEIGHT / 2;
	cub->half_width = WIDTH / 2;
	cub->fps.frame_duration = 1000.0 / TARGET_FPS;
	cub->fov = 60 * (M_PI / 180);
	cub->projection_plane = (cub->half_width) / tan(cub->fov / 2.0);
	cub->scale = (double)cub->half_height / 200.0;
	cub->color[1] = create_trgb(0, cub->cfg.ceil_rgb[0],
			cub->cfg.ceil_rgb[1], cub->cfg.ceil_rgb[2]);
	cub->color[0] = create_trgb(0, cub->cfg.floor_rgb[0],
			cub->cfg.floor_rgb[1], cub->cfg.floor_rgb[2]);
	cub->fps.frames = 0;
	cub->fps.last_time = 0.0;
	cub->fps.last_frame_time = get_time_ms();
	cub->fps.delta_time = 0.0;
}

static void	init_player(t_cub *cub)
{
	cub->p.size = PLY_SIZE;
	cub->p.half = PLY_SIZE / 2;
	get_player_cfg(cub);
	cub->p.move_up = false;
	cub->p.move_down = false;
	cub->p.move_left = false;
	cub->p.move_right = false;
	cub->p.rotate_left = false;
	cub->p.rotate_right = false;
	cub->p.cos_a = cos(cub->p.angle);
	cub->p.sin_a = sin(cub->p.angle);
}

static void	init_map(t_cub *cub)
{
	cub->map.array = cub->cfg.map;
	cub->map.w = cub->cfg.map_w;
	cub->map.h = cub->cfg.map_h;
}

int	init_cub(t_cub	*cub)
{
	cub->mlx = NULL;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (EXIT_FAILURE);
	cub->mlx_win = NULL;
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	if (!cub->mlx_win)
		return (EXIT_FAILURE);
	init_default_values(cub);
	init_map(cub);
	init_player(cub);
	init_image_buffer(cub);
	return (EXIT_SUCCESS);
}
