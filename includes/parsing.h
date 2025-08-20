/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:02:26 by wahmane           #+#    #+#             */
/*   Updated: 2025/08/20 22:35:41 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSING_H
# define PARSING_H


typedef struct s_color {
	int r;
	int g;
	int b;
}   t_color;

typedef struct s_config {
	char    *no_texture;
	char    *so_texture;
	char    *we_texture;
	char    *ea_texture;
	t_color floor;
	t_color ceiling;
	char    **map;
	int     map_width;
	int     map_height;
	int     player_x;
	int     player_y;
	char    player_dir; // 'N','S','E','W'
}			t_config;

void    parsing(int ac, char **av);

#endif