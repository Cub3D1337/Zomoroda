/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:11:32 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/19 16:52:33 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	destroy_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < TEX_NUM)
	{
		if (cub->textures[i].img_ptr)
			mlx_destroy_image(cub->mlx, cub->textures[i].img_ptr);
		i++;
	}
		i = 0;
	while (i < cub->obj.sprites_num)
	{
		if (cub->obj.sprites[i].img_ptr)
			mlx_destroy_image(cub->mlx, cub->obj.sprites[i].img_ptr);
		if (cub->obj.inspect_sprites[i].img_ptr)
			mlx_destroy_image(cub->mlx, cub->obj.inspect_sprites[i].img_ptr);
		i++;
	}
}

void	destroy_cub(t_cub *cub)
{
	destroy_textures(cub);
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx, cub->img.img_ptr);
	if (cub->map_img.img_ptr)
		mlx_destroy_image(cub->mlx, cub->map_img.img_ptr);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
}

int	ft_exit(t_cub *cub)
{
	destroy_cub(cub);
	ft_printf("Programme exit successfuly\n");
	exit(EXIT_SUCCESS);
}
