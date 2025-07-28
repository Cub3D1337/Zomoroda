/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:41:46 by hwahmane          #+#    #+#             */
/*   Updated: 2025/07/28 14:31:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void reset_player(t_cub *cub)
{
	// draw_square(cub, cub->p.prev_x - (cub->p.half), cub->p.prev_y - (cub->p.half), cub->p.size, 0x00ff00);
	t_pointi	incr_pos;
	t_pointi	norm_pos;
	// int			color;

	norm_pos.y = (int)cub->p.prev_y - (cub->p.half);
	norm_pos.x = (int)cub->p.prev_x - (cub->p.half);
	incr_pos.y = 0;
	while (incr_pos.y < cub->p.size)
	{
		incr_pos.x = 0;
		while (incr_pos.x < cub->p.size)
		{
			// color = *(unsigned int *)(cub->img.img_pixels_ptr
			// 		+ (norm_pos.y * cub->img.line_length + norm_pos.x * (cub->img.bits_per_pixel / 8)));
			put_pixel(cub, (norm_pos.x + incr_pos.x),
				(norm_pos.y + incr_pos.y), 0x00ff00);
			incr_pos.x++;
		}
		incr_pos.y++;
	}
}

t_bool	check_boundaries(t_cub *cub)
{
	t_pointi	ply_corners[4];
	int			i;

	if ((int)cub->p.x - cub->p.half < 0
		||(int) cub->p.x + cub->p.half >= (MAP_WIDTH * MAP_SIZE) + 1
		|| (int)cub->p.y - cub->p.half < 0
		|| (int)cub->p.y + cub->p.half >= (MAP_HEIGHT * MAP_SIZE) + 1)
		return (false);
	// Check actual corners of the square (in tile units)
	ply_corners[0].x = (cub->p.x - cub->p.half) / MAP_SIZE; // Top-Left
	ply_corners[0].y = (cub->p.y - cub->p.half) / MAP_SIZE;
	ply_corners[1].x = (cub->p.x + cub->p.half - 1) / MAP_SIZE; // Top-Right
	ply_corners[1].y = (cub->p.y - cub->p.half) / MAP_SIZE;
	ply_corners[2].x = (cub->p.x - cub->p.half) / MAP_SIZE; // Bottom-Left
	ply_corners[2].y = (cub->p.y + cub->p.half - 1) / MAP_SIZE;
	ply_corners[3].x = (cub->p.x + cub->p.half - 1) / MAP_SIZE; // Bottom-Right
	ply_corners[3].y = (cub->p.y + cub->p.half - 1) / MAP_SIZE;
	i = 0;
	while (i < 4)
	{	
		if (cub->map.array[ply_corners[i].y][ply_corners[i].x] == 1)
			return (false);
		i++;
	}
	return (true);
}


void move(t_cub *cub)
{
	double	speed;
	if (cub->p.move_up || cub->p.move_down
		|| cub->p.move_left || cub->p.move_right)
	{
		// Save previous position BEFORE moving
		cub->p.prev_y = cub->p.y;
		cub->p.prev_x = cub->p.x;
		speed = SPEED * (cub->delta_time * 2);
		// Move
		if (cub->p.move_up)
			cub->p.y -= speed;
		if (cub->p.move_down)
			cub->p.y += speed;
		if (cub->p.move_left)
			cub->p.x -= speed;
		if (cub->p.move_right)
			cub->p.x += speed;

		// Ilegale move out of image buffer (out of Window)
		if (check_boundaries(cub) == false)
		{
			cub->p.y = cub->p.prev_y;
			cub->p.x = cub->p.prev_x;
			return ;
		}

		// Reset the square at previous position
		reset_player(cub); // NOW this will use prev_x / prev_y

		// Draw player at new position
		draw_player(cub);

		// Render frame
		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img_ptr, 0, 0);
	}
}

