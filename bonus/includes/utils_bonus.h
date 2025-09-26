/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:11:22 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 00:14:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "includes_bonus.h"

void			put_pixel(t_cub *cub, int x, int y, int color);
unsigned int	get_texel(const t_img_texture *t, int tx, int ty);
int				create_trgb(int t, int r, int g, int b);
double			get_time_ms(void);
void			get_player_cfg(t_cub *cub);
t_bool			check_minimap_edge(int x, int y);
t_bool			check_screen_edge(int x, int y);
int				ft_exit(t_cub *cub);

#endif
