/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:11:22 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/30 15:14:59 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "includes.h"

void	put_pixel(t_cub *cub, int x, int y, int color);
double	get_time_ms(void);
void	get_player_pos(t_cub *cub);
t_bool	check_minimap_edge(int x, int y);
void	destroy_cub(t_cub *cub);
int		ft_exit(t_cub *cub);

#endif