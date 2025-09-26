/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:54:31 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/26 15:48:10 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_loop_hook(t_cub *cub)
{
	if (!cub)
		return (EXIT_FAILURE);
	if (cub->state == STATE_MENU)
		return (state_menu(cub));
	else if (cub->state == STATE_LOADING)
		return (state_loading(cub));
	else if (cub->state == STATE_INTRO)
		return (state_intro(cub));
	else if (cub->state == STATE_RENDER)
		return (state_render(cub));
	else if (cub->state == STATE_EXIT)
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	mouse_hook(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		cub->obj.frame = 0;
		cub->obj.inspect = true;
	}
	if (button == 3)
		cub->track_mouse = !cub->track_mouse;
	return (0);
}

void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, ON_KEYDOWN, KeyPressMask, ft_key_press, cub);
	mlx_hook(cub->mlx_win, ON_KEYUP, KeyReleaseMask, ft_key_release, cub);
	mlx_hook(cub->mlx_win, ON_DESTROY, DestroyNotifyMask, ft_exit, cub);
	mlx_hook(cub->mlx_win, ON_MOUSE_MOVE, PointerMotionMask,
		ft_mouse_move, cub);
	mlx_mouse_hook(cub->mlx_win, mouse_hook, cub);
	mlx_loop_hook(cub->mlx, ft_loop_hook, cub);
}
