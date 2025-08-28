/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:28:06 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/28 18:55:42 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_pointi
{
	int	x;
	int	y;
}				t_pointi;

typedef struct s_pointd
{
	double	x;
	double	y;
}				t_pointd;

typedef struct s_map_data
{
	int	array[MAP_HEIGHT][MAP_WIDTH];
	int	minimap_width;
	int	minimap_height;
	int	padding;
}				t_map_data;

typedef struct t_map_ctx
{
	t_pointd		s;
	t_pointd		e;
	t_pointd		norm_ply_pos;
	t_pointi		rows;
}			t_map_ctx;

typedef struct s_img
{
	// Fast rendering
	unsigned int	*pixels;
	unsigned int	pitch;
	// Img members
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

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

typedef struct s_player
{
	t_pointd	pos;
	t_pointd	prev_pos;
	int		size;
	int		half;
	t_bool	move_up;
	t_bool	move_down;
	t_bool	move_left;
	t_bool	move_right;
	t_bool	rotate_left;
	t_bool	rotate_right;
	double	angle;
	double	cosA;
	double	sinA;
	double	pitch;
	double	horizon;
	t_bool	rotate_up;
	t_bool	rotate_down;
}				t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	int			half_height;
	int			half_width;
	t_img		img;
	t_img		map_img;
	t_map_data	map;
	t_player	p;
	// Textures
	t_img_texture	textures[4];
	//TODO: Default calculation
	double	frame_duration;
	double	fov;
	// Projection Plan
	double		projection_plane;
	// COLOR
	int			color[2];
	// Mouse
	t_pointd	mouse;
	t_bool		track_mouse;
	// FPS
	int			frames;
	int			fps;
	double		last_time;
	double		last_frame_time;
	double		delta_time;
	// Debug
}			t_cub;

typedef enum e_side
{
	HORIZONTAL,
	VERTICAL,
}			t_side;

typedef struct s_dda
{
	t_pointi	map_pos;
	t_pointd	p_cell;
	t_pointi	dir_step;
	t_pointd	grid_step;
	t_bool		hit;
	t_side		side;			
	t_pointd	hypotenuse_dist;
}				t_dda;

typedef struct s_dda_result
{
	t_side		side;
	t_pointi	dir_step;
	t_pointi	map_pos;
	t_pointd	hit_point;
	double		dist;
}				t_dda_result;

typedef struct s_texture_data
{
	t_img_texture	*tex;
	double			wallX;
	t_pointi		tex_cord;
	double			step;
	double			tex_pos;
	int				color;
}				t_texture_data;

typedef struct s_rect
{
	t_pointi	pos;
	int			len;
	int			wid;
	t_side		side;
	int			color;
}				t_rect;

typedef struct s_line
{
	t_pointi	start;
	double		angle;
	int			line_len;
	int			color;
}				t_line;

#endif
