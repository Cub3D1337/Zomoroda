/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:28:06 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/25 17:41:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "./typedef/dda.h"
# include "./typedef/global.h"
# include "./typedef/tex_type.h"
# include "settings.h"

typedef struct s_config
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	int				floor_rgb[3];
	int				ceil_rgb[3];
	char			**map;
	int				map_h;
	int				map_w;
	int				player_x;
	int				player_y;
	char			player_dir;
}					t_config;

typedef struct s_vec
{
	char			**data;
	int				size;
	int				cap;
}					t_vec;

typedef struct s_map_data
{
	// int	array[MAP_HEIGHT][MAP_WIDTH];
	char			**array;
	int				w;
	int				h;
	int				minimap_width;
	int				minimap_height;
	int				padding;
}					t_map_data;

typedef struct t_map_ctx
{
	t_pointd		s;
	t_pointd		e;
	t_pointd		norm_ply_pos;
	t_pointi		rows;
}					t_map_ctx;

typedef struct s_img
{
	// Fast rendering
	unsigned int	*pixels;
	unsigned int	pitch;
	// Img members
	void			*img_ptr;
	char			*img_pixels_ptr;
	int				bits_per_pixel;
	int				bytes_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_player
{
	t_pointd		pos;
	t_pointd		prev_pos;
	int				size;
	int				half;
	t_bool			move_up;
	t_bool			move_down;
	t_bool			move_left;
	t_bool			move_right;
	t_bool			rotate_left;
	t_bool			rotate_right;
	double			angle;
	double			cos_a;
	double			sin_a;
	double			pitch;
	double			horizon;
	t_bool			rotate_up;
	t_bool			rotate_down;
}					t_player;

typedef struct s_fps
{
	int				frames;
	int				fps;
	double			last_time;
	double			last_frame_time;
	double			delta_time;
	double			frame_duration;
}					t_fps;

typedef struct s_animate
{
	t_bool			inspect;
	t_img_texture	sprites[MAX_SPRITES];
	t_img_texture	inspect_sprites[MAX_SPRITES];
	int				sprites_num;
	int				frame;
	double			timer;
	double			frame_duration;
	double			last_update;
	t_pointi		offset;
}					t_animate;

typedef struct s_intro
{
	char			*logo_path;
	char			*intro_path;
	char			*door_path;
	char			*obj_path;
	char			*obj_click_path;
	t_img_texture	intro_textures[182];
	double			last_time;
	int				intro_index;
	t_bool			intro_done;
}				t_intro;

typedef struct s_sprite
{
	t_pointi		pos;
	t_pointi		cord;
	t_pointi		deplacement;
	t_pointi		scaled;
	t_pointi		tex;
	int				color;
}					t_sprite;

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	int				half_height;
	int				half_width;
	t_img			img;
	int				flag;
	t_img			map_img;
	t_map_data		map;
	t_player		p;
	t_config		cfg;
	// Textures
	t_img_texture	logo_texture;
	t_intro			intro;
	t_img_texture	textures[5];
	t_animate		obj;
	//TODO: Default calculation
	double			fov;
	// Projection Plan
	double			projection_plane;
	double			scale;
	// COLOR
	int				color[2];
	// Mouse
	t_pointd		mouse;
	t_bool			track_mouse;
	t_fps			fps;
}					t_cub;

#endif
