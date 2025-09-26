/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:50:00 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/26 23:25:34 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "includes.h"

int		prepare_sprite_metadata(t_cub *cub, t_img_texture *t);
int		init_textures(t_cub *cub);
void	mapping_textures(t_cub *cub, t_ray_ctx *ctx);

#endif
