/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:58:04 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 00:14:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "includes_bonus.h"

void	raycasting(t_cub *cub);
void	dda(t_cub *cub, t_pointd ray_dir, t_dda_result *result);
void	setup_dda(t_cub *cub, t_dda *dda, t_pointd ray_dir);

#endif
