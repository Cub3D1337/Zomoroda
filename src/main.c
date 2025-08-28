/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/28 15:53:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_cub	cub;
	// t_config	cfg;

	// init_config(&cfg);
	// if (parsing(ac, av, &cfg) == 0)
	// 	return (EXIT_FAILURE);
	init_map(&cub);
	init_cub(&cub);
	init_textures(&cub);
	init_image_buffer(&cub);
	init_map_image_buffer(&cub);
	init_events(&cub);
	mlx_loop(cub.mlx);
	ft_exit(&cub);
	// free_config(&cfg);
	return (EXIT_SUCCESS);
}
