/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:40:04 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/25 16:24:48 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	ray_dir = (t_pointd){cub->p.cos_a, cub->p.sin_a};
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
	else if (keycode == UP_KEY)
		cub->p.rotate_up = flag;
	else if (keycode == DOWN_KEY)
		cub->p.rotate_down = flag;
}

int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == ESCAPE_KEY)
			ft_exit(cub);
	else if (keycode == E_KEY)
		toggle_door(cub);
	else
		toggle_mvt(keycode, cub, true);
	if (cub->flag == 0)
	{
		if (keycode == OPTION_1)
			cub->flag = 1;
		else if (keycode == OPTION_2)
			cub->flag = 2;
	}
	return (EXIT_SUCCESS);
}

int	ft_key_release(int keycode, t_cub *cub)
{
	toggle_mvt(keycode, cub, false);
	return (EXIT_SUCCESS);
}
