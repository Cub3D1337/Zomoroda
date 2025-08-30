/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/30 20:37:08 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//TODO: Init textures for parsing cfg
static void	set_texture_paths(t_cub *cub)
{
	cub->textures[0].relative_path = "./textures/north.xpm";
	cub->textures[0].img_width = 64;
	cub->textures[0].img_height = 64;
	cub->textures[1].relative_path = "./textures/south.xpm";
	cub->textures[1].img_width = 64;
	cub->textures[1].img_height = 64;
	cub->textures[2].relative_path = "./textures/east.xpm";
	cub->textures[2].img_width = 64;
	cub->textures[2].img_height = 64;
	cub->textures[3].relative_path = "./textures/west.xpm";
	cub->textures[3].img_width = 64;
	cub->textures[3].img_height = 64;
}

static void	prepare_texture_fast_fields(t_img_texture *t)
{
	t->pixels_u32 = (unsigned int *)t->img_pixels_ptr;
	t->pitch_u32 = (unsigned int)(t->line_length / sizeof(unsigned int));
}

int	init_textures(t_cub *cub)
{
	int	i;

	i = 0;
	set_texture_paths(cub);
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
		cub->textures[i].img_pixels_ptr = mlx_get_data_addr(
				cub->textures[i].img_ptr, &cub->textures[i].bits_per_pixel,
				&cub->textures[i].line_length, &cub->textures[i].endian
				);
		prepare_texture_fast_fields(&cub->textures[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
