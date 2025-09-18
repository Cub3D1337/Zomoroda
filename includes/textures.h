/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:50:00 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/05 17:49:18 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "includes.h"

int		init_textures(t_cub *cub, t_config *cfg);
int	    init_sprites(t_cub *cub);
void	mapping_textures(t_cub *cub, t_tex_ctx *ctx);

#endif
