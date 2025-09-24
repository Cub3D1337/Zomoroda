/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:20:50 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/24 18:38:43 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	play_music(t_bool music)
{
	if (music == 0)
		system("vlc --intf dummy Music/intro.mp3 > /dev/null 2>&1 &");
	else
		system("vlc --intf dummy --loop Music/zomoroda.mp3 > /dev/null 2>&1 &");
}

void	stop_music(void)
{
	system("killall vlc");
}
