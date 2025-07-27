/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:11:32 by hwahmane          #+#    #+#             */
/*   Updated: 2025/07/27 12:12:16 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	destroy_cub(t_cub *cub)
{
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx, cub->img.img_ptr);
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
