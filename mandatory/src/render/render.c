/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/27 08:54:15 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling_and_floor(t_cub *cub)
{
	unsigned int	color;
	t_pointi		pos;
	int				row;

	pos.y = 0;
	while (pos.y < HEIGHT)
	{
		pos.x = 0;
		color = cub->color[pos.y < cub->half_height];
		row = pos.y * cub->img.pitch;
		while (pos.x < WIDTH)
		{
			cub->img.pixels[row + pos.x] = color;
			pos.x++;
		}
		pos.y++;
	}
}

void	render(t_cub *cub)
{
	char	*fps_notif;

	draw_ceiling_and_floor(cub);
	raycasting(cub);
	fps_notif = ft_conststrjoin(ft_strdup("FPS: "), ft_itoa(cub->fps.fps));
	mlx_put_image_to_window(cub->mlx, cub->mlx_win,
		cub->img.img_ptr, 0, 0);
	mlx_string_put(cub->mlx, cub->mlx_win, WIDTH - 80, 30, 0xFFFFFF, fps_notif);
	free(fps_notif);
}
