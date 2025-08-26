/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:40:04 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/26 15:42:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>

int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == ESCAPE_KEY)
	{
		if (cub->track_mouse)
		{
			mlx_mouse_show(cub->mlx, cub->mlx_win);
			cub->track_mouse = false;
		}
		else
			ft_exit(cub);			
	}
	else if (keycode == W_KEY)
		cub->p.move_up = true;
	else if (keycode == S_KEY)
		cub->p.move_down = true;
	else if (keycode == A_KEY)
		cub->p.move_left = true;
	else if (keycode == D_KEY)
		cub->p.move_right = true;
	if (keycode == LEFT_KEY)
		cub->p.rotate_left = true;
	else if (keycode == RIGHT_KEY)
		cub->p.rotate_right = true;
	else if (keycode == UP_KEY)
		cub->p.rotate_up = true;
	else if (keycode == DOWN_KEY)
		cub->p.rotate_down = true;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == W_KEY)
		cub->p.move_up = false;
	else if (keycode == S_KEY)
		cub->p.move_down = false;
	else if (keycode == A_KEY)
		cub->p.move_left = false;
	else if (keycode == D_KEY)
		cub->p.move_right = false;
	if (keycode == LEFT_KEY)
		cub->p.rotate_left = false;
	else if (keycode == RIGHT_KEY)
		cub->p.rotate_right = false;
	else if (keycode == UP_KEY)
		cub->p.rotate_up = false;
	else if (keycode == DOWN_KEY)
		cub->p.rotate_down = false;
	return (EXIT_SUCCESS);
}
