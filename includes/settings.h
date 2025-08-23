/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:15:21 by hwahmane          #+#    #+#             */
/*   Updated: 2025/08/23 17:56:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

#ifndef M_PI
#	define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
#	define M_PI_2 1.57079632679489661923
#endif

# define WIDTH 1280
# define HEIGHT 720

# define TARGET_FPS 900
# define FRAME_DURATION (1000.0 / TARGET_FPS) // ~16.66 ms for each frame == 60 FPS

# define MAP_WIDTH 32
# define MAP_HEIGHT 32
# define BLOCK_SIZE  12
# define MINIMAP_SIZE 220

# define TINY_STEP 0.5
# define PLY_SIZE 4
# define SPEED 50

# define H_ROT_SPEED 3.5
# define V_ROT_SPEED 1000
# define MAX_PITCH HEIGHT
# define MIN_PITCH -HEIGHT
# define YAW_SENSITIVITY 0.0007
# define PITCH_SENSITIVITY 0.5

# define TEX_NUM 4

// # define FOV M_PI / 3	
# define FOV (60 * (M_PI / 180)) // Convert 60° to radians



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
