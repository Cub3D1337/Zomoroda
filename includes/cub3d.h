/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/07/27 13:00:30 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "../Libft/includes/libft.h"
# include <sys/time.h>
# include <stdio.h>
# include "settings.h"
# include "typedef.h"

void init_map(t_cub	*cub);
void init_cub(t_cub	*cub);
void	init_image_buffer(t_cub *cub);



void	draw_square(t_cub *cub, int x, int y, int size, int color);
void	draw_map(t_cub *cub);
void	draw_player(t_cub *cub);
void	draw(t_cub *cub);


void	init_events(t_cub *cub);

void    move(t_cub *cub);

void   get_player_pos(t_cub *cub);
void	put_pixel(t_cub *cub, int x, int y, int color);
double	get_time_ms(void);


void	destroy_cub(t_cub *cub);
int	ft_exit(t_cub *cub);



#endif