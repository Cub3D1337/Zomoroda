/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:05:24 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 16:58:42 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "includes.h"

// Map Buffer
void	draw_init_minimap(t_cub *cub);
// Animation
void	animation(t_cub *cub);
// MAP Chunk
void	draw_minimap(t_cub *cub);
void	render(t_cub *cub);

int	ft_loop_hook(t_cub *cub);

#endif
