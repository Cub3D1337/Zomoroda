/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:27:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 00:18:33 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0));
}

void	get_player_cfg(t_cub *cub)
{
	cub->p.pos.x = (cub->cfg.player_x * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	cub->p.pos.y = (cub->cfg.player_y * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	if (cub->cfg.player_dir == 'N')
		cub->p.angle = (3 * M_PI) / 2;
	else if (cub->cfg.player_dir == 'S')
		cub->p.angle = M_PI / 2;
	else if (cub->cfg.player_dir == 'W')
		cub->p.angle = 0;
	else if (cub->cfg.player_dir == 'E')
		cub->p.angle = M_PI;
}

unsigned int	get_texel(const t_img_texture *t, int tx, int ty)
{
	if (!t || !t->img_pixels_ptr || !t->pixels_u32)
		return (0);
	if (tx < 0 || tx >= t->img_w || ty < 0 || ty >= t->img_h)
		return (0);
	return (t->pixels_u32[(unsigned int)ty * t->pitch_u32 + (unsigned int)tx]);
}
