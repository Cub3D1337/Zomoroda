/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:50:00 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/07 11:11:35 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "includes.h"

void	set_texture_paths(t_cub *cub);
int		init_textures(t_cub *cub);
void	mapping_textures(t_cub *cub, t_pointd ray_dir, t_dda_result result
	, int x, double line_height, int start_y, int end_y);

#endif
