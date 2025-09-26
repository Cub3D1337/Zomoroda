/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:11:32 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/26 22:40:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_text_arr(t_cub *cub, t_img_texture *arr, int text_num)
{
	int	i;

	i = 0;
	while (i < text_num)
	{
		if (arr[i].img_ptr)
			mlx_destroy_image(cub->mlx, arr[i].img_ptr);
		i++;
	}
}

static void	destroy_textures(t_cub *cub)
{
	if (cub->logo_texture.img_ptr)
		mlx_destroy_image(cub->mlx, cub->logo_texture.img_ptr);
	clear_text_arr(cub, cub->textures, TEX_NUM);
	clear_text_arr(cub, cub->intro.intro_textures, INTRO_NUM);
}

static void	destroy_cub(t_cub *cub)
{
	free_config(&(cub->cfg));
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
	if (!cub || !cub->mlx)
		exit(EXIT_SUCCESS);
	cub->state = STATE_EXIT;
	stop_music();
	destroy_cub(cub);
	printf("Program exited successfully\n");
	exit(EXIT_SUCCESS);
}
