/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/20 22:34:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"
# include "parsing.h"

void    init_map(t_cub	*cub);
void    init_cub(t_cub	*cub);
void	init_image_buffer(t_cub *cub);

void	init_image(t_cub *cub);
void	dup_map(t_cub *cub);
void	init_map_image_buffer(t_cub *cub);

void	draw_line(t_cub *cub, int x, int y, double angle, int line_len, int color);
void	draw_line_to(t_cub *cub, t_pointd from, t_pointd to, int color);
void	draw_square(t_cub *cub, int x, int y, int size, int color);
void	draw_map(t_cub *cub);
void	draw_player(t_cub *cub);
void	draw(t_cub *cub);
//TODO: Map buffer
void	draw_init_map(t_cub *cub);


void	init_events(t_cub *cub);

void    move(t_cub *cub);

t_bool	check_minimap_edge(int x, int y);
void	raycasting(t_cub *cub);
void	dda(t_cub *cub, t_pointd ray_dir, t_dda_result *result);

void   get_player_pos(t_cub *cub);
void	put_pixel(t_cub *cub, int x, int y, int color);
double	get_time_ms(void);


void	destroy_cub(t_cub *cub);
int	ft_exit(t_cub *cub);

#endif