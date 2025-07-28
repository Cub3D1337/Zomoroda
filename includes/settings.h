/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:15:21 by hwahmane          #+#    #+#             */
/*   Updated: 2025/07/28 13:48:13 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# define WIDTH 1080
# define HEIGHT 720

#define TARGET_FPS 60
#define FRAME_DURATION (1000.0 / TARGET_FPS) // ~16.66 ms for each frame == 60 FPS

# define MAP_WIDTH 16
# define MAP_HEIGHT 16
# define MAP_SIZE  20

# define SPEED 20
# define ROT_SPEED 0.015
# define PLY_SIZE 6

enum e_events_hooks
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17,
};

enum e_events_masks
{
	DestroyNotifyMask = 0L,
	KeyPressMask = 1L << 0,
	KeyReleaseMask = 1L << 1,
	PointerMotionMask = 1L << 6,
};

enum e_events_inputs
{
	ZOOM_IN = 4,
	ZOOM_OUT = 5,
	INCREASE_BUTTON = 1,
	DECREASE_BUTTON = 3,
	LEFT_KEY = 65361,
	UP_KEY = 65362,
	RIGHT_KEY = 65363,
	DOWN_KEY = 65364,
	ESCAPE_KEY = 65307,
	SHIFT_KEY = 65505,
	SPACE_KEY = 32,
	H_KEY = 104,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
};

#endif
