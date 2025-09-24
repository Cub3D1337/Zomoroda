/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 22:50:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	loading(t_cub *cub)
{
	if (init_cub(cub))
		return (EXIT_FAILURE);
	if (put_logo(cub))
		return (EXIT_FAILURE);
	if (load_textures(cub))
		return (EXIT_FAILURE);
	init_events(cub);
	play_music(0);
	if (put_intro(cub))
		return (EXIT_FAILURE);
	stop_music();
	play_music(1);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init_config(&(cub.cfg));
	if (parsing(ac, av, &(cub.cfg)) == 0)
		return (EXIT_FAILURE);
	loading(&cub);
	mlx_loop(cub.mlx);
	ft_exit(&cub);
	return (EXIT_SUCCESS);
}
