/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:28:06 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/19 20:15:58 by abnsila          ###   ########.fr       */
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
}				t_map_data;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_img_texture {
	void			*img_ptr;
	char			*img_pixels_ptr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	char			*relative_path;
	int				img_width;
	int				img_height;
}				t_img_texture;

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
}				t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_map_data	map;
	t_player	p;

	// Textures
	t_img_texture	textures[4];

	//TODO: Default calculation
	// Projection Plan
	double		projection_plane;
	
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

#endif