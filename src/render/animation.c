/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:55:40 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/07 16:29:17 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>

static unsigned int	get_texel(const t_img_texture *t, int tx, int ty)
{
	if (!t || !t->img_pixels_ptr || !t->pixels_u32)
		return (0);
	if (tx < 0 || tx >= t->img_width || ty < 0 || ty >= t->img_height)
		return (0);
	return (t->pixels_u32[(unsigned int)ty * t->pitch_u32 + (unsigned int)tx]);
}

static void	draw_sprite(t_cub *cub, t_img_texture *t)
{
	t_pointi	pos;
	t_pointi	cord;
	int			color;
	t_pointi	deplacement;
	
	pos = (t_pointi){0, 0};
	deplacement = (t_pointi){cub->half_width - (t->img_width / 2)
			, HEIGHT - t->img_height};
	while (pos.y < t->img_height)
	{
		pos.x = 0;
		cord.y = (pos.y + deplacement.y + cub->gun.offset.y + 50) * cub->img.pitch;
		while (pos.x < t->img_width)
		{
			color = get_texel(t, pos.x, pos.y);
			cord.x = pos.x + deplacement.x + cub->gun.offset.x;
			if (check_screen_edge(cord.x, cord.y / cub->img.pitch) && color != 0xFF000000)
				cub->img.pixels[cord.y + cord.x] = color;
			pos.x++;
		}
		pos.y++;
	}
}

static void	update_y_gun_offset(t_cub *cub)
{
	// Vertical offset (movement up/down)
	if (cub->p.move_up && cub->gun.offset.y < GUN_OFFSET)
		cub->gun.offset.y += (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else if (cub->p.move_down && cub->gun.offset.y > -GUN_OFFSET)
		cub->gun.offset.y -= (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else
	{
		// ease back toward 0 when no vertical input
		if (cub->gun.offset.y > 0)
		{
			cub->gun.offset.y -= GUN_OFFSET_SPEED * cub->fps.delta_time;
			if (cub->gun.offset.y < 0)
				cub->gun.offset.y = 0;
		}
		else if (cub->gun.offset.y < 0)
		{
			cub->gun.offset.y += GUN_OFFSET_SPEED * cub->fps.delta_time;
			if (cub->gun.offset.y > 0)
				cub->gun.offset.y = 0;
		}
	}
}

static void	update_x_gun_offset(t_cub *cub)
{
	// Horizontal offset (movement left/right)
	if (cub->p.move_left && cub->gun.offset.x < GUN_OFFSET)
		cub->gun.offset.x += (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else if (cub->p.move_right && cub->gun.offset.x > -GUN_OFFSET)
		cub->gun.offset.x -= (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else
	{
		// ease back toward 0 when no horizontal input
		if (cub->gun.offset.x > 0)
		{
			cub->gun.offset.x -= GUN_OFFSET_SPEED * cub->fps.delta_time;
			if (cub->gun.offset.x < 0)
				cub->gun.offset.x = 0;
		}
		else if (cub->gun.offset.x < 0)
		{
			cub->gun.offset.x += GUN_OFFSET_SPEED * cub->fps.delta_time;
			if (cub->gun.offset.x > 0)
				cub->gun.offset.x = 0;
		}
	}
}

void	animation(t_cub *cub)
{
	double	current_time;
	double	delta_time;

	update_y_gun_offset(cub);
	update_x_gun_offset(cub);
	
   current_time = get_time_ms() / 1000.0; // Current time in seconds
   delta_time = current_time - cub->gun.last_update;
	// Update the timer with the time passed since last frame
	cub->gun.timer += delta_time;
	// Advance frames if enough time has passed
	while (cub->gun.timer >= cub->gun.frame_duration)
	{
		cub->gun.timer -= cub->gun.frame_duration;
		cub->gun.frame = (cub->gun.frame + 1) % cub->gun.sprites_num;
	}
	// Update the last update time
	cub->gun.last_update = current_time;
	// Draw current frame
	draw_sprite(cub, &cub->gun.sprites[cub->gun.frame]);
}
