/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:08:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 08:55:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image_buffer(t_cub *cub)
{
	cub->img.img_ptr = mlx_new_image(cub->mlx,
			WIDTH, HEIGHT);
	cub->img.img_pixels_ptr = mlx_get_data_addr(cub->img.img_ptr,
			&cub->img.bits_per_pixel, &cub->img.line_length,
			&cub->img.endian);
	cub->img.bytes_per_pixel = cub->img.bits_per_pixel / 8;
	cub->img.pixels = (unsigned int *) cub->img.img_pixels_ptr;
	cub->img.pitch = cub->img.line_length / sizeof(unsigned int);
}
