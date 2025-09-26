/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 00:14:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "includes_bonus.h"
# include "events_bonus.h"
# include "music_bonus.h"
# include "parsing_bonus.h"
# include "raycasting_bonus.h"
# include "render_bonus.h"
# include "textures_bonus.h"
# include "utils_bonus.h"

int		load_textures(t_cub *cub);
int		init_cub(t_cub *cub);
void	init_image_buffer(t_cub *cub);
void	init_map_image_buffer(t_cub *cub);
void	init_events(t_cub *cub);

#endif
