/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:27:26 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 00:14:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_BONUS_H
# define DDA_BONUS_H

# include "global_bonus.h"

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

#endif