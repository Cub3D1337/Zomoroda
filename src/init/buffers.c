/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:08:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 19:08:15 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

void	init_map_image_buffer(t_cub *cub)
{
	cub->map_img.img_ptr = mlx_new_image(cub->mlx,
			cub->map.minimap_width, cub->map.minimap_height);
	cub->map_img.img_pixels_ptr = mlx_get_data_addr(cub->map_img.img_ptr,
			&cub->map_img.bits_per_pixel, &cub->map_img.line_length,
			&cub->map_img.endian);
	cub->map_img.bytes_per_pixel = cub->map_img.bits_per_pixel / 8;
	cub->map_img.pixels = (unsigned int *) cub->map_img.img_pixels_ptr;
	cub->map_img.pitch = cub->map_img.line_length / sizeof(unsigned int);
	draw_init_minimap(cub);
}
