/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:28:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/24 15:05:31 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUSIC_H
# define MUSIC_H


#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>

void stop_loop_music();
int play_music_loop(const char *filename, int loop);

#endif