/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:28:06 by hwahmane          #+#    #+#             */
/*   Updated: 2025/07/28 12:39:07 by abnsila          ###   ########.fr       */
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
	int	array[16][16];
}				t_map_data;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	prev_x;
	double	prev_y;
	int		size;
	int		half;
	t_bool	move_up;
	t_bool	move_down;
	t_bool	move_left;
	t_bool	move_right;
	t_bool	rotate_left;
	t_bool	rotate_right;
	double	angle;
}				t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_map_data	map;
	t_player	p;

	// FPS
	int			frames;
	int			fps;
	double		last_time;
	double		last_frame_time;
	double		delta_time;
}			t_cub;

#endif