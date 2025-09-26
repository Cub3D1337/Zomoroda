/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:02:58 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/27 00:08:09 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(unsigned int *)(cub->img.img_pixels_ptr
			+ (y * cub->img.line_length + x * cub->img.bytes_per_pixel))
		= color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_bool	check_minimap_edge(int x, int y)
{
	if (x >= MINIMAP_SIZE + BORDER * 2
		|| y >= MINIMAP_SIZE + BORDER * 2)
		return (true);
	return (false);
}

t_bool	check_screen_edge(int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (false);
	return (true);
}
