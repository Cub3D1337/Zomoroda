/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:56:26 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/25 16:33:54 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_default_values(t_cub *cub)
{
	cub->flag = MENU;
	cub->half_height = HEIGHT / 2;
	cub->half_width = WIDTH / 2;
	cub->map.padding = MINIMAP_SIZE / 2;
	cub->fps.frame_duration = 1000.0 / TARGET_FPS;
	cub->fov = 60 * (M_PI / 180);
	cub->projection_plane = (cub->half_width) / tan(cub->fov / 2.0);
	cub->scale = (double)cub->half_height / 200.0;
	cub->mouse.x = cub->half_width;
	cub->mouse.y = cub->half_height;
	cub->track_mouse = true;
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
	cub->p.rotate_up = false;
	cub->p.rotate_down = false;
	cub->p.cos_a = cos(cub->p.angle);
	cub->p.sin_a = sin(cub->p.angle);
	cub->p.pitch = 0.0;
	cub->p.horizon = cub->half_height;
}

static void	init_map(t_cub *cub)
{
	cub->map.array = cub->cfg.map;
	cub->map.w = cub->cfg.map_w;
	cub->map.h = cub->cfg.map_h;
	cub->map.minimap_width = (cub->cfg.map_w * BLOCK_SIZE) + MINIMAP_SIZE;
	cub->map.minimap_height = (cub->cfg.map_h * BLOCK_SIZE) + MINIMAP_SIZE;
}

int	load_textures(t_cub	*cub)
{
	if (init_intro(cub) == 1)
		return (EXIT_FAILURE);
	if (init_sprites(cub) == 1)
		return (EXIT_FAILURE);
	if (init_textures(cub) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_cub(t_cub	*cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (EXIT_FAILURE);
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	if (!cub->mlx_win)
		return (EXIT_FAILURE);
	init_default_values(cub);
	init_map(cub);
	init_player(cub);
	init_image_buffer(cub);
	init_map_image_buffer(cub);
	return (EXIT_SUCCESS);
}
