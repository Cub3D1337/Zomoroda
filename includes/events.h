/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:35:50 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/25 23:39:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "includes.h"

void	mouse_handler(t_cub *cub);
int		ft_mouse_move(int x, int y, t_cub *cub);
int		ft_key_press(int keycode, t_cub *cub);
int		ft_key_release(int keycode, t_cub *cub);
t_bool	check_boundaries(t_cub *cub);
int		state_menu(t_cub *cub);
int		state_loading(t_cub *cub);
int		state_intro(t_cub *cub);
int		state_render(t_cub *cub);
void	move(t_cub *cub);

#endif
