/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:56:26 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/26 15:43:54 by abnsila          ###   ########.fr       */
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

static inline void	init_player(t_cub *cub)
{
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
	cub->p.rotate_up = false;
	cub->p.rotate_down = false;
	cub->p.angle = (3 * M_PI) / 2;
	cub->p.cosA = cos(cub->p.angle);
	cub->p.sinA = sin(cub->p.angle);
	cub->p.pitch = 0.0;
	cub->p.horizon = cub->half_height;
}

static inline void	init_defult_calculation(t_cub *cub)
{
	// Screen
	cub->half_height = HEIGHT / 2;
	cub->half_width = WIDTH / 2;
	// Minimap
	cub->map.minimap_width = (MAP_WIDTH * BLOCK_SIZE) + MINIMAP_SIZE;
	cub->map.minimap_height = (MAP_HEIGHT * BLOCK_SIZE) + MINIMAP_SIZE;
	cub->map.padding = MINIMAP_SIZE / 2;
	// Settings
	cub->frame_duration = 1000.0 / TARGET_FPS; // ~16.66 ms for each frame == 60 FPS
	cub->fov = 60 * (M_PI / 180); // Convert 60° to radians
	// Projection Plan
	cub->projection_plane = (cub->half_width) / tan(cub->fov / 2.0);
	// Mouse
	cub->mouse.x = cub->half_width;
	cub->mouse.y = cub->half_height;
}

int	init_cub(t_cub	*cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (EXIT_FAILURE);
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	if (!cub->mlx_win)
		return (EXIT_FAILURE);
	init_defult_calculation(cub);
	init_player(cub);
	cub->track_mouse = true;
	// COLOR
	cub->color[1] = 0x0099FF;
	cub->color[0] = 0x333333;
	// Utils
	cub->frames = 0;
	cub->last_time = 0.0;
	cub->last_frame_time = 0.0;
	return (EXIT_SUCCESS);
}

void	init_image_buffer(t_cub *cub)
{
	cub->img.img_ptr = mlx_new_image(cub->mlx,
			WIDTH, HEIGHT);
	cub->img.img_pixels_ptr = mlx_get_data_addr(cub->img.img_ptr,
			&cub->img.bits_per_pixel, &cub->img.line_length,
			&cub->img.endian);
	// For put_pixel inline pointer math
	cub->img.bytes_per_pixel = cub->img.bits_per_pixel / 8;
	// Fast rendering
	cub->img.pixels = (unsigned int *) cub->img.img_pixels_ptr;
	cub->img.pitch = cub->img.line_length / sizeof(unsigned int);
}

void	init_map_image_buffer(t_cub *cub)
{
	//TODO: The initial setup of a buffer for the map image require:
	//TODO: The long HORIZONTAL row = MAP_WIDTH
	//TODO: The long VERTICAL = MAP_HIGHT
	//TODO: Padding for each edge = MINIMAP_SIZE / 2
	cub->map_img.img_ptr = mlx_new_image(cub->mlx,
			cub->map.minimap_width, cub->map.minimap_height);
	cub->map_img.img_pixels_ptr = mlx_get_data_addr(cub->map_img.img_ptr,
			&cub->map_img.bits_per_pixel, &cub->map_img.line_length,
			&cub->map_img.endian);
	// For put_pixel inline pointer math
	cub->map_img.bytes_per_pixel = cub->map_img.bits_per_pixel / 8;
	// Fast rendering
	cub->map_img.pixels = (unsigned int *) cub->map_img.img_pixels_ptr;
	cub->map_img.pitch = cub->map_img.line_length / sizeof(unsigned int);
	draw_init_map(cub);
}

static inline void prepare_texture_fast_fields(t_img_texture *t)
{
    t->pixels_u32 = (unsigned int*)t->img_pixels_ptr;
    t->pitch_u32  = (unsigned int)(t->line_length  / sizeof(unsigned int));
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
		prepare_texture_fast_fields(&cub->textures[i]);
		i++;
	}
	return (0);
}

