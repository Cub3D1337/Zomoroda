/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:56:26 by hwahmane          #+#    #+#             */
/*   Updated: 2025/07/28 13:27:15 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void init_map(t_cub	*cub)
{

	int tmp[16][16] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1},
    {1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,1},
    {1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,2,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			cub->map.array[i][j] = tmp[i][j];
}

void init_cub(t_cub	*cub)
{

	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	// Init Player
	cub->p.size = PLY_SIZE;
	cub->p.half = PLY_SIZE / 2;
	get_player_pos(cub);
    // MVT
    cub->p.move_up = false;
	cub->p.move_down = false;
    cub->p.move_left = false;
	cub->p.move_right = false;
	cub->p.rotate_left = false;
	cub->p.rotate_right = false;
	// cub->p.angle = (3 * M_PI) / 2;
	// Utils
	cub->frames = 0;
	cub->last_time = 0.0;
	cub->last_frame_time = 0.0;
}

void	init_image_buffer(t_cub *cub)
{
	// if (cub->img.img_ptr)
	// 	mlx_destroy_image(cub->mlx, cub->img.img_ptr);
	cub->img.img_ptr = mlx_new_image(cub->mlx,
			WIDTH, HEIGHT);
	cub->img.img_pixels_ptr = mlx_get_data_addr(cub->img.img_ptr,
			&cub->img.bits_per_pixel, &cub->img.line_length,
			&cub->img.endian);
}
