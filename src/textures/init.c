/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 16:13:31 by abnsila          ###   ########.fr       */
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

static void	set_sprites_paths(t_cub *cub)
{
	cub->obj.sprites[0].relative_path = "./textures/animation/bear/1.xpm";
	cub->obj.sprites[1].relative_path = "./textures/animation/bear/2.xpm";
	cub->obj.sprites[2].relative_path = "./textures/animation/bear/3.xpm";
	cub->obj.sprites[3].relative_path = "./textures/animation/bear/4.xpm";
	cub->obj.inspect_sprites[0].relative_path
		= "./textures/animation/bear_click/1.xpm";
	cub->obj.inspect_sprites[1].relative_path
		= "./textures/animation/bear_click/2.xpm";
	cub->obj.inspect_sprites[2].relative_path
		= "./textures/animation/bear_click/3.xpm";
	cub->obj.inspect_sprites[3].relative_path
		= "./textures/animation/bear_click/4.xpm";
}

int	prepare_sprite_metadata(t_cub *cub, t_img_texture *t)
{
	if (!t)
		return (EXIT_FAILURE);
	t->img_ptr = mlx_xpm_file_to_image(
			cub->mlx,
			t->relative_path,
			&t->img_width,
			&t->img_height
			);
	if (!t->img_ptr)
	{
		printf("Failed to load Texture: %s\n", t->relative_path);
		return (EXIT_FAILURE);
	}
	t->img_pixels_ptr = mlx_get_data_addr(
			t->img_ptr, &t->bits_per_pixel,
			&t->line_length, &t->endian
			);
	t->pixels_u32 = (unsigned int *)t->img_pixels_ptr;
	t->pitch_u32 = (unsigned int)(t->line_length / sizeof(unsigned int));
	return (EXIT_SUCCESS);
}

int	init_textures(t_cub *cub, t_config *cfg)
{
	int	i;

	i = 0;
	set_texture_paths(cub, cfg);
	while (i < TEX_NUM)
	{
		if (prepare_sprite_metadata(cub, &cub->textures[i]) == 1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_sprites(t_cub *cub)
{
	int	i;

	i = 0;
	cub->obj.inspect = false;
	cub->obj.frame = 0;
	cub->obj.timer = 0.0;
	cub->obj.frame_duration = 0.15;
	cub->obj.last_update = get_time_ms() / 1000.0;
	cub->obj.sprites_num = 4;
	cub->obj.offset = (t_pointi){0, 0};
	set_sprites_paths(cub);
	while (i < cub->obj.sprites_num)
	{
		if (prepare_sprite_metadata(cub, &cub->obj.sprites[i]) == 1)
			return (EXIT_FAILURE);
		if (prepare_sprite_metadata(cub, &cub->obj.inspect_sprites[i]) == 1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
