/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:02:26 by wahmane           #+#    #+#             */
/*   Updated: 2025/08/20 16:12:08 by wahmane          ###   ########.fr       */
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
}   t_config;

#endif