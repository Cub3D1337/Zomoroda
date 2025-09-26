/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:05:24 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/26 22:27:10 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void	draw_init_minimap(t_cub *cub);
void	draw_minimap(t_cub *cub);
void	render(t_cub *cub);
int		ft_loop_hook(t_cub *cub);

#endif
