/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_type_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:25:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 00:18:33 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEX_TYPE_BONUS_H
# define TEX_TYPE_BONUS_H

# include "global_bonus.h"
# include "dda_bonus.h"

typedef struct s_img_texture
{
	unsigned int	*pixels_u32;
	unsigned int	pitch_u32;
	void			*img_ptr;
	char			*img_pixels_ptr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*relative_path;
	int				img_w;
	int				img_h;
}			t_img_texture;

typedef struct s_texture_data
{
	t_img_texture	*tex;
	double			wall_x;
	t_pointi		tex_cord;
	double			step;
	double			tex_pos;
	int				color;
}				t_texture_data;

#endif
