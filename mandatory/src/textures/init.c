/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/26 23:04:17 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_texture_paths(t_cub *cub)
{
	cub->textures[NORTH].relative_path = cub->cfg.no_texture;
	cub->textures[SOUTH].relative_path = cub->cfg.so_texture;
	cub->textures[WEST].relative_path = cub->cfg.we_texture;
	cub->textures[EAST].relative_path = cub->cfg.ea_texture;
}

int	prepare_sprite_metadata(t_cub *cub, t_img_texture *t)
{
	if (!t)
		return (EXIT_FAILURE);
	t->img_ptr = NULL;
	if (validate_texture_file(t->relative_path, "loading sprite") == 0)
		return (EXIT_FAILURE);
	t->img_ptr = mlx_xpm_file_to_image(
			cub->mlx,
			t->relative_path,
			&t->img_w,
			&t->img_h
			);
	if (!t->img_ptr)
	{
		fdprintf(2, "Failed to load Texture: %s\n", t->relative_path);
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

int	init_textures(t_cub *cub)
{
	int	i;

	i = 0;
	set_texture_paths(cub);
	while (i < TEX_NUM)
	{
		if (prepare_sprite_metadata(cub, &cub->textures[i]) == 1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
