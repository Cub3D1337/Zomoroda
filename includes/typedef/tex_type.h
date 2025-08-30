/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:25:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/30 15:37:41 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEX_TYPE_H
# define TEX_TYPE_H

# include "global.h"
# include "dda.h"

typedef struct s_img_texture
{
	// Hot (read every pixel)
	unsigned int   *pixels_u32;
	unsigned int    pitch_u32;
	// MLX
	void           *img_ptr;
	char           *img_pixels_ptr;
	int             bits_per_pixel;
	int             line_length;
	int             endian;
	// Meta
	char           *relative_path;
	int             img_width;
	int             img_height;
}			t_img_texture;

typedef struct s_texture_data
{
	t_img_texture	*tex;
	double			wallX;
	t_pointi		tex_cord;
	double			step;
	double			tex_pos;
	int				color;
}				t_texture_data;

typedef struct s_tex_ctx
{
	t_pointd		ray_dir;
	t_dda_result	result;
	int				x;
	double			line_height;
	int				start_y;
	int				end_y;
}				t_tex_ctx;

#endif
