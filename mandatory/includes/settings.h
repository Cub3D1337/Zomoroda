/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:15:21 by hwahmane          #+#    #+#             */
/*   Updated: 2025/09/27 09:01:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923
# endif

# define WIDTH 1080
# define HEIGHT 720

# define TARGET_FPS 1000

# define BLOCK_SIZE 18

# define TINY_STEP 0.5
# define PLY_SIZE 4
# define SPEED 150

# define H_ROT_SPEED 3.5
# define X_SENSITIVITY 0.0007

# define TEX_NUM 4

enum	e_events_hooks
{
	ON_DESTROY = 17,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
};

enum	e_events_masks
{
	DestroyNotifyMask = 0L,
	KeyPressMask = 1L << 0,
	KeyReleaseMask = 1L << 1,
};

enum	e_events_inputs
{
	ESCAPE_KEY = 65307,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
};

#endif
