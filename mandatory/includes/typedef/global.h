/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:24:14 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 09:03:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "../../Libft/includes/libft.h"

typedef enum e_side
{
	HORIZONTAL,
	VERTICAL,
}			t_side;

typedef enum e_tex_side
{
	SOUTH,
	NORTH,
	WEST,
	EAST,
}			t_tex_side;

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

#endif
