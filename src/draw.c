/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/07 10:29:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_square(t_cub *cub, int x, int y, int size, int color)
{
	t_pointi	incr_pos;

	incr_pos.y = 0;
	while (incr_pos.y < size)
	{
		incr_pos.x = 0;
		while (incr_pos.x < size)
		{
			put_pixel(cub, (x + incr_pos.x), (y + incr_pos.y), color);
			incr_pos.x++;
		}
		incr_pos.y++;
	}
}

void	draw_map(t_cub *cub)
{
	t_pointi	pos;
	int			color;

	pos.y = 0;
	while (pos.y < MAP_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < MAP_WIDTH)
		{
			if (cub->map.array[pos.y][pos.x] == 1)
				color = 0xffffff;
			else
				color = 0x000000;
			draw_square(cub, pos.x * MAP_SIZE, pos.y * MAP_SIZE, MAP_SIZE, color);
			pos.x++;
		}
		pos.y++;
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

void	draw_line_to(t_cub *cub, t_pointd from, t_pointd to, int color)
{
	int			i;
	double		steps;
	t_pointd	dist;
	t_pointd	inc;
	t_pointd	start;
	
	i = 0;
	dist.x = to.x - from.x;
	dist.y = to.y - from.y;
	steps = fmax(fabs(dist.x), fabs(dist.y));
	inc.x = dist.x / steps;
	inc.y = dist.y / steps;
	start.x = from.x;
	start.y = from.y;
	while (i <= steps)
	{
		put_pixel(cub, (int)start.x, (int)start.y, color);
		start.x += inc.x;
		start.y += inc.y;
		i++;
	}
}

void	draw_player(t_cub *cub)
{
	t_pointi	pos;
	double		radiant_angle;

	draw_square(cub, cub->p.pos.x - (cub->p.half), cub->p.pos.y - (cub->p.half), cub->p.size, 0xff0000);
	draw_line(cub, cub->p.pos.x, cub->p.pos.y, cub->p.angle, 20, 0xff0000);
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
	draw_map(cub);
	raycasting(cub);
	draw_player(cub);
	show_fps(cub);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img_ptr, 0, 0);
}
