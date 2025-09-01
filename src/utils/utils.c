/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:02:58 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/30 19:20:36 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

double	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

void	get_player_cfg(t_cub *cub, t_config *cfg)
{
	cub->p.pos.x = (cfg->player_x * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	cub->p.pos.y = (cfg->player_y * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	if (cfg->player_dir == 'N')
		cub->p.angle = (3 * M_PI) / 2;
	else if (cfg->player_dir == 'S')
		cub->p.angle = M_PI / 2;
	else if (cfg->player_dir == 'W')
		cub->p.angle = 0;
	else if (cfg->player_dir == 'E')
		cub->p.angle = M_PI;
}

t_bool	check_minimap_edge(int x, int y)
{
	if (x >= MINIMAP_SIZE + BORDER * 2
		|| y >= MINIMAP_SIZE + BORDER * 2)
		return (true);
	return (false);
}
