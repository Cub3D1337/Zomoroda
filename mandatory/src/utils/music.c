/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:20:50 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/26 22:31:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_music(t_cub *cub, t_audio_state audio_state)
{
	t_game_mode	*mode;
	char		command[512];

	if (cub->selected_mode < 0 || cub->selected_mode >= cub->mode_count)
		return ;
	mode = &cub->modes[cub->selected_mode];
	if (audio_state == ONCE)
	{
		snprintf(command, sizeof(command),
			"vlc --intf dummy \"%sMusic/intro.mp3\" > /dev/null 2>&1 &",
			mode->global_path);
	}
	else
	{
		snprintf(command, sizeof(command),
			"vlc --intf dummy --loop \"%sMusic/loop.mp3\" > /dev/null 2>&1 &",
			mode->global_path);
	}
	system(command);
}

void	stop_music(void)
{
	system("killall -q vlc 2>/dev/null");
}
