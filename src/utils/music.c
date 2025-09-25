/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:20:50 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/25 17:49:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	play_music(t_bool music, int flag)
{
	if (music == 0)
	{
		if (flag == LAODING_1)
			system("vlc --intf dummy textures/zomoroda/Music/intro.mp3 > /dev/null 2>&1 &");
		else
			system("vlc --intf dummy textures/action/Music/intro.mp3 > /dev/null 2>&1 &");
	}
	else
	{
		if (flag == LAODING_1)
			system("vlc --intf dummy --loop textures/zomoroda/Music/loop.mp3 > /dev/null 2>&1 &");
		else
			system("vlc --intf dummy --loop textures/action/Music/loop.mp3 > /dev/null 2>&1 &");
	}
}

void	stop_music(void)
{
	system("killall vlc");
}
