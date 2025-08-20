/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:56:26 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/20 18:34:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void init_map(t_cub	*cub)
{

	// int tmp[MAP_HEIGHT][MAP_WIDTH] = {
	// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	// {1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
	// {1,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1},
	// {1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,1},
	// {1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1},
	// {1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,1},
	// {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
	// {1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
	// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	// {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	// {1,0,1,2,0,0,0,0,0,0,0,0,0,0,0,1},
	// {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	// };

	int tmp[MAP_HEIGHT][MAP_WIDTH] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,0,1,0,1},
		{1,0,0,0,0,1,0,0,1,0,1,1,0,1,0,0,0,0,1,0,0,1,1,0,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1},
		{1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1},
		{1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			cub->map.array[i][j] = tmp[i][j];
}

void	init_defult_calculation(t_cub *cub)
{
	//TODO: MAP
	cub->map.map_width = (MAP_WIDTH * BLOCK_SIZE) + MINIMAP_SIZE;
	cub->map.map_height = (MAP_HEIGHT * BLOCK_SIZE) + MINIMAP_SIZE;
	cub->map.padding = MINIMAP_SIZE / 2;
	// Projection Plan
	cub->projection_plane = (WIDTH / 2.0) / tan(FOV / 2.0);
	// Cos / Sin of player angle
	cub->p.cosA = cos(cub->p.angle);
	cub->p.sinA = sin(cub->p.angle);
}

void	init_cub(t_cub	*cub)
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
	cub->p.angle = (3 * M_PI) / 2;
	// Utils
	cub->frames = 0;
	cub->last_time = 0.0;
	cub->last_frame_time = 0.0;
	init_defult_calculation(cub);
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
	// For put_pixel inline pointer math
	cub->img.bytes_per_pixel = cub->img.bits_per_pixel / 8;
}

void	init_map_image_buffer(t_cub *cub)
{
	// if (cub->map_img.img_ptr)
	// 	mlx_destroy_image(cub->mlx, cub->map_img.img_ptr);
	//TODO: The initial setup of a buffer for the map image require:
	//TODO: The long HORIZONTAL row = MAP_WIDTH
	//TODO: The long VERTICAL = MAP_HIGHT
	//TODO: Padding for each edge = MINIMAP_SIZE / 2
	cub->map_img.img_ptr = mlx_new_image(cub->mlx,
			(MAP_WIDTH * BLOCK_SIZE) + MINIMAP_SIZE,
			(MAP_HEIGHT * BLOCK_SIZE) + MINIMAP_SIZE);
	cub->map_img.img_pixels_ptr = mlx_get_data_addr(cub->map_img.img_ptr,
			&cub->map_img.bits_per_pixel, &cub->map_img.line_length,
			&cub->map_img.endian);
	// For put_pixel inline pointer math
	cub->map_img.bytes_per_pixel = cub->map_img.bits_per_pixel / 8;
	draw_init_map(cub);
}

int	init_textures(t_cub *cub)
{
	int	i;

	i = 0;
	set_texture_paths(cub);
	while (i < TEX_NUM)
	{
		// Load the image from file
		cub->textures[i].img_ptr = mlx_xpm_file_to_image(
			cub->mlx,
			cub->textures[i].relative_path,
			&cub->textures[i].img_width,
			&cub->textures[i].img_height
		);
		if (!cub->textures[i].img_ptr)
		{
			printf("Failed to load texture %s\n", cub->textures[i].relative_path);
			return (1);
		}

		// Get image address and metadata
		cub->textures[i].img_pixels_ptr = mlx_get_data_addr(
			cub->textures[i].img_ptr,
			&cub->textures[i].bits_per_pixel,
			&cub->textures[i].line_length,
			&cub->textures[i].endian
		);
		i++;
	}
	return (0);
}

