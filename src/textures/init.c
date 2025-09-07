/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/07 16:36:40 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	set_texture_paths(t_cub *cub, t_config *cfg)
{
	cub->textures[NORTH].relative_path = cfg->no_texture;
	cub->textures[SOUTH].relative_path = cfg->so_texture;
	cub->textures[WEST].relative_path = cfg->we_texture;
	cub->textures[EAST].relative_path = cfg->ea_texture;
	cub->textures[DOOR].relative_path = "./textures/door.xpm";
}

static void	prepare_texture_metadata(t_cub *cub, int i)
{
	t_img_texture	*t;

	t = &cub->textures[i];
	t->img_pixels_ptr = mlx_get_data_addr(
				t->img_ptr, &t->bits_per_pixel,
				&t->line_length, &t->endian
				);
	t->pixels_u32 = (unsigned int *)t->img_pixels_ptr;
	t->pitch_u32 = (unsigned int)(t->line_length / sizeof(unsigned int));
}

//TODO: diffrent from door
int	init_textures(t_cub *cub, t_config *cfg)
{
	int	i;

	i = 0;
	set_texture_paths(cub, cfg);
	while (i < TEX_NUM)
	{
		cub->textures[i].img_ptr = mlx_xpm_file_to_image(
				cub->mlx,
				cub->textures[i].relative_path,
				&cub->textures[i].img_width,
				&cub->textures[i].img_height
				);
		if (!cub->textures[i].img_ptr)
		{
			printf("Failed to load tex: %s\n", cub->textures[i].relative_path);
			return (EXIT_FAILURE);
		}
		prepare_texture_metadata(cub, i);
		i++;
	}
	return (EXIT_SUCCESS);
}


// ================================= Animated sprites ===============================

static void	set_sprites_paths(t_cub *cub)
{
	// 8 frames
	cub->gun.sprites[0].relative_path = "./textures/animation/gun/sprite_0.xpm";
	cub->gun.sprites[1].relative_path = "./textures/animation/gun/sprite_1.xpm";
	cub->gun.sprites[2].relative_path = "./textures/animation/gun/sprite_2.xpm";
	cub->gun.sprites[3].relative_path = "./textures/animation/gun/sprite_3.xpm";
}

static void	prepare_sprite_metadata(t_cub *cub, int i)
{
	t_img_texture	*t;

	t = &cub->gun.sprites[i];
	t->img_pixels_ptr = mlx_get_data_addr(
				t->img_ptr, &t->bits_per_pixel,
				&t->line_length, &t->endian
				);
	t->pixels_u32 = (unsigned int *)t->img_pixels_ptr;
	t->pitch_u32 = (unsigned int)(t->line_length / sizeof(unsigned int));
}

int	init_sprites(t_cub *cub)
{
	int	i;
	
	i = 0;
	cub->gun.frame = 0;
    cub->gun.timer = 0.0;
    cub->gun.frame_duration = 0.06; // Each frame lasts 0.1 seconds (10 FPS animation)
    cub->gun.last_update = get_time_ms() / 1000.0; // Convert to seconds
    cub->gun.sprites_num = 4;
    cub->gun.offset = (t_pointi){0, 0};
	set_sprites_paths(cub);
	// Init sprites image buffers
	while (i < cub->gun.sprites_num)
	{
		cub->gun.sprites[i].img_ptr = mlx_xpm_file_to_image(
				cub->mlx,
				cub->gun.sprites[i].relative_path,
				&cub->gun.sprites[i].img_width,
				&cub->gun.sprites[i].img_height
				);
		if (!cub->gun.sprites[i].img_ptr)
		{
			printf("Failed to load sprite: %s\n", cub->gun.sprites[i].relative_path);
			return (EXIT_FAILURE);
		}
		prepare_sprite_metadata(cub, i);
		i++;
	}
	return (EXIT_SUCCESS);
}
