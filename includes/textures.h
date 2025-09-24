/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:50:00 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 15:09:30 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "includes.h"

int		put_logo(t_cub *cub);
void	put_intro(t_cub *cub);

int		prepare_sprite_metadata(t_cub *cub, t_img_texture *t);
int		init_intro(t_cub *cub);
int		init_textures(t_cub *cub);
int	    init_sprites(t_cub *cub);
void	mapping_textures(t_cub *cub, t_tex_ctx *ctx);

#endif
