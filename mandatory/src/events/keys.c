/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:40:04 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 08:45:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	toggle_mvt(int keycode, t_cub *cub, t_bool flag)
{
	if (keycode == W_KEY)
		cub->p.move_up = flag;
	else if (keycode == S_KEY)
		cub->p.move_down = flag;
	else if (keycode == A_KEY)
		cub->p.move_left = flag;
	else if (keycode == D_KEY)
		cub->p.move_right = flag;
	if (keycode == LEFT_KEY)
		cub->p.rotate_left = flag;
	else if (keycode == RIGHT_KEY)
		cub->p.rotate_right = flag;
}

int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == ESCAPE_KEY)
		ft_exit(cub);
	toggle_mvt(keycode, cub, true);
	return (EXIT_SUCCESS);
}

int	ft_key_release(int keycode, t_cub *cub)
{
	toggle_mvt(keycode, cub, false);
	return (EXIT_SUCCESS);
}
