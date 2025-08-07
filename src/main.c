/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/06 16:06:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_cub	cub;

	(void)ac;
	(void)av;
	init_map(&cub);
	init_cub(&cub);
	init_image_buffer(&cub);
	init_events(&cub);
	mlx_loop(cub.mlx);
	ft_exit(&cub);
	return (EXIT_SUCCESS);
}
