/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:40:04 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 22:32:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	toggle_escape(int keycode, t_cub *cub)
{
	if (keycode == ESCAPE_KEY)
	{
		if (cub->track_mouse)
			cub->track_mouse = false;
		else
			ft_exit(cub);
	}
}

static t_bool	check_door_state(t_cub *cub, t_dda *dda)
{
	char	*cell;

	if (dda->map_pos.x < 0 || dda->map_pos.x >= cub->map.w
		|| dda->map_pos.y < 0 || dda->map_pos.y >= cub->map.h)
		return (false);
	cell = &cub->map.array[dda->map_pos.y][dda->map_pos.x];
	if (*cell == 'D')
	{
		*cell = 'd';
		return (false);
	}
	else if (*cell == 'd')
	{
		*cell = 'D';
		return (false);
	}
	return (true);
}

static void	toggle_door(t_cub *cub)
{
	t_dda		dda;
	t_pointd	ray_dir;
	int			i;

	i = 0;
	ray_dir = (t_pointd){cub->p.cosA, cub->p.sinA};
	setup_dda(cub, &dda, ray_dir);
	while (i < TRACK_DOOR_CELL)
	{
		if (dda.hypotenuse_dist.x <= dda.hypotenuse_dist.y)
		{
			dda.hypotenuse_dist.x += dda.grid_step.x;
			dda.map_pos.x += dda.dir_step.x;
			dda.side = HORIZONTAL;
		}
		else
		{
			dda.hypotenuse_dist.y += dda.grid_step.y;
			dda.map_pos.y += dda.dir_step.y;
			dda.side = VERTICAL;
		}
		if (check_door_state(cub, &dda) == false)
			break ;
		i++;
	}
}

int	ft_key_press(int keycode, t_cub *cub)
{
	toggle_escape(keycode, cub);
	if (keycode == W_KEY)
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
	else if (keycode == E_KEY)
		toggle_door(cub);
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
