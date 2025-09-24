/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 22:54:36 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "events.h"
# include "includes.h"
# include "music.h"
# include "parsing.h"
# include "raycasting.h"
# include "render.h"
# include "textures.h"
# include "utils.h"

int		load_textures(t_cub *cub);
int		init_cub(t_cub *cub);
void	init_image_buffer(t_cub *cub);
void	init_map_image_buffer(t_cub *cub);
void	init_events(t_cub *cub);

#endif
