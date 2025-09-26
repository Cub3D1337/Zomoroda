/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/26 21:41:15 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_cub	cub;
	while(1);

	ft_memset((void *)&cub, 0, sizeof(t_cub));
	init_config(&(cub.cfg));
	if (parsing(ac, av, &(cub.cfg)) == 0)
		return (EXIT_FAILURE);
	if (init_cub(&cub))
		return (EXIT_FAILURE);
	init_events(&cub);
	mlx_loop(cub.mlx);
	ft_exit(&cub);
	return (EXIT_SUCCESS);
}
