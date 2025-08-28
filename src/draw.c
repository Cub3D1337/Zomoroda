/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/28 18:59:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_square(t_cub *cub, t_pointi start, int size, int color)
{
	t_pointi	incr_pos;
	int			row;

	incr_pos.y = 0;
	while (incr_pos.y < size)
	{
		incr_pos.x = 0;
		row = (start.y + incr_pos.y) * cub->img.pitch;
		while (incr_pos.x < size)
		{
			cub->img.pixels[row + start.x + incr_pos.x] = color;
			incr_pos.x++;
		}
		incr_pos.y++;
	}
}

void	draw_line(t_cub *cub, t_line line)
{
	int			i;
	t_pointi	pos;
	t_pointd	ang_dir;

	i = 0;
	ang_dir = (t_pointd){cos(line.angle), sin(line.angle)};
	while (i < line.line_len)
	{
		pos.x = line.start.x + ang_dir.x * i;
		pos.y = line.start.y + ang_dir.y * i;
		put_pixel(cub, pos.x, pos.y, line.color);
		i++;
	}
}

void	draw_player(t_cub *cub)
{
	t_pointi	pos;
	t_pointi	minimap_pos;

	minimap_pos.x = (MINIMAP_SIZE / 2) + BORDER;
	minimap_pos.y = (MINIMAP_SIZE / 2) + BORDER;
	draw_square(cub,
		(t_pointi){minimap_pos.x - cub->p.half, minimap_pos.y - cub->p.half},
		cub->p.size, 0xff0000);
	draw_line(cub, (t_line){(t_pointi){minimap_pos.x, minimap_pos.y},
		cub->p.angle, 20, 0xff0000});
}

void	draw_ceiling_and_floor(t_cub *cub)
{
	unsigned int	color;
	t_pointi		pos;

	pos.y = 0;
	while (pos.y < HEIGHT)
	{
		pos.x = 0;
		color = cub->color[pos.y < cub->p.horizon];
		while (pos.x < WIDTH)
		{
			if (pos.x < MINIMAP_SIZE && pos.y < MINIMAP_SIZE)
			{
				pos.x++;
				continue ;
			}
			cub->img.pixels[pos.y * cub->img.pitch + pos.x] = color;
			pos.x++;
		}
		pos.y++;
	}
}

void	show_fps(t_cub *cub)
{
	

	
	
}

void	render(t_cub *cub)
{
	char	*fps_notif;
	draw_ceiling_and_floor(cub);
	draw_map(cub);
	raycasting(cub);
	draw_player(cub);
	fps_notif = ft_conststrjoin(ft_strdup("FPS: "), ft_itoa(cub->fps));
	mlx_put_image_to_window(cub->mlx, cub->mlx_win,
		cub->img.img_ptr, 0, 0);
	mlx_string_put(cub->mlx, cub->mlx_win, WIDTH - 80, 30, 0xFFFFFF, fps_notif);
	free(fps_notif);
}
