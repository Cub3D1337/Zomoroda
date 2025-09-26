/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:25:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/26 16:14:33 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEX_TYPE_H
# define TEX_TYPE_H

# include "global.h"
# include "dda.h"

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
