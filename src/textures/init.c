/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:17:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/01 14:19:27 by abnsila          ###   ########.fr       */
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
	// if (i == TEX_NUM - 1)
	// {	
	// 	cub->textures[i].is_door = true;
	// 	cub->textures[i].status = CLOSE;
	// }
	// else
	// 	cub->textures[i].is_door = false;
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
