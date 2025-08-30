/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:35:50 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/30 15:04:52 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

# include "includes.h"

// Mouse
void	mouse_handler(t_cub *cub);
int		ft_mouse_move(int x, int y, t_cub *cub);

// Keys
int		ft_key_press(int keycode, t_cub *cub);
int		ft_key_release(int keycode, t_cub *cub);

// MVT
void	move(t_cub *cub);

#endif


