/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/20 21:20:34 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_square(t_cub *cub, int x, int y, int size, int color)
{
	t_pointi	incr_pos;
	unsigned int	*pixels;
	unsigned int	pitch;

	incr_pos.y = 0;
	pixels = (unsigned int *) cub->img.img_pixels_ptr;
	pitch = cub->img.line_length / sizeof(unsigned int);
	while (incr_pos.y < size)
	{
		incr_pos.x = 0;
		while (incr_pos.x < size)
		{
			pixels[(y + incr_pos.y) * pitch + (x + incr_pos.x)] = color;
			incr_pos.x++;
		}
		incr_pos.y++;
	}
}

void	draw_line(t_cub *cub, int x, int y, double angle, int line_len, int color)
{
	int			i;
	t_pointi	pos;

	i = 0;
	while (i < line_len)
	{
		pos.x = x + cos(angle) * i;
		pos.y = y + sin(angle) * i;
		put_pixel(cub, pos.x, pos.y, color);
		i++;
	}
}

void	draw_player(t_cub *cub)
{
	t_pointi	pos;
	double		radiant_angle;
	t_pointi	minimap_pos;

	minimap_pos.x = (MINIMAP_SIZE / 2);
	minimap_pos.y = (MINIMAP_SIZE / 2);
	draw_square(cub, minimap_pos.x - cub->p.half, minimap_pos.y - cub->p.half, cub->p.size, 0xff0000);
	draw_line(cub, minimap_pos.x, minimap_pos.y, cub->p.angle, 20, 0xff0000);
}

void	draw_sky_and_floor(t_cub *cub)
{
	unsigned int	color;
	t_pointi		pos;
	unsigned int	*pixels;
	unsigned int	pitch;

	pos.y = 0;
	pixels = (unsigned int *) cub->img.img_pixels_ptr;
	pitch = cub->img.line_length / sizeof(unsigned int);
	while (pos.y < HEIGHT)
	{
		pos.x = 0;
		if ((pos.y < HEIGHT / 2))
			color = 0x0099ff;
		else
			color = 0x005500;
		while (pos.x < WIDTH)
		{
			if (pos.x < MINIMAP_SIZE && pos.y < MINIMAP_SIZE)
			{
				pos.x++;
				continue ;
			}
			if (!(pos.x < 0 || pos.x >= WIDTH || pos.y < 0 || pos.y >= HEIGHT))
				pixels[pos.y * pitch + pos.x] = color;
			pos.x++;
		}
		pos.y++;
	}	
}

void	show_fps(t_cub *cub)
{
	char	*fps_notif;

	fps_notif = ft_conststrjoin(ft_strdup("FPS: "), ft_itoa(cub->fps));
	mlx_put_image_to_window(cub->mlx, cub->mlx_win,
		cub->img.img_ptr, 0, 0);
	mlx_string_put(cub->mlx, cub->mlx_win, WIDTH - 80, 30, 0xFFFFFF, fps_notif);
	free(fps_notif);
}

void	draw(t_cub *cub)
{
	ft_memset(cub->img.img_pixels_ptr, 0,
		HEIGHT * cub->img.line_length);
	draw_sky_and_floor(cub);
	draw_map(cub);
	raycasting(cub);
	draw_player(cub);
	show_fps(cub);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img_ptr, 0, 0);
}
