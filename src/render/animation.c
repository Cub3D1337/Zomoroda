/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:55:40 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 16:19:14 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>

// static void	draw_sprite(t_cub *cub, t_img_texture *t)
// {
// 	t_pointi	pos;
// 	t_pointi	cord;
// 	int			color;
// 	t_pointi	deplacement;
	
// 	pos = (t_pointi){0, 0};
// 	deplacement = (t_pointi){cub->half_width - (t->img_width / 2)
// 			, HEIGHT - t->img_height};
// 	while (pos.y < t->img_height)
// 	{
// 		pos.x = 0;
// 		cord.y = (pos.y + deplacement.y + cub->obj.offset.y + 50) * cub->img.pitch;
// 		while (pos.x < t->img_width)
// 		{
// 			color = get_texel(t, pos.x, pos.y);
// 			cord.x = pos.x + deplacement.x + cub->obj.offset.x;
// 			if (check_screen_edge(cord.x, cord.y / cub->img.pitch) && color != 0xFF000000)
// 				cub->img.pixels[cord.y + cord.x] = color;
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// }


static void	draw_sprite(t_cub *cub, t_img_texture *t, double scale)
{
	t_pointi	pos;
	t_pointi	cord;
	int			color;
	t_pointi	deplacement;
	int			scaled_w;
	int			scaled_h;

	if (!t || scale <= 0.0)
		return;

	scaled_w = (int)(t->img_width * scale);
	scaled_h = (int)(t->img_height * scale);

	deplacement = (t_pointi){
		cub->half_width - (scaled_w / 2),
		HEIGHT - scaled_h
	};

	pos.y = 0;
	while (pos.y < scaled_h)
	{
		pos.x = 0;
		// map scaled y to original texture y
		int tex_y = (int)((double)pos.y / scale);
		cord.y = (pos.y + deplacement.y + cub->obj.offset.y + 50) * cub->img.pitch;

		while (pos.x < scaled_w)
		{
			// map scaled x to original texture x
			int tex_x = (int)((double)pos.x / scale);
			color = get_texel(t, tex_x, tex_y);

			cord.x = pos.x + deplacement.x + cub->obj.offset.x;
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
	if (cub->p.move_up && cub->obj.offset.y < GUN_OFFSET)
		cub->obj.offset.y += (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else if (cub->p.move_down && cub->obj.offset.y > -GUN_OFFSET)
		cub->obj.offset.y -= (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else
	{
		// ease back toward 0 when no vertical input
		if (cub->obj.offset.y > 0)
		{
			cub->obj.offset.y -= GUN_OFFSET_SPEED * cub->fps.delta_time;
			if (cub->obj.offset.y < 0)
				cub->obj.offset.y = 0;
		}
		else if (cub->obj.offset.y < 0)
		{
			cub->obj.offset.y += GUN_OFFSET_SPEED * cub->fps.delta_time;
			if (cub->obj.offset.y > 0)
				cub->obj.offset.y = 0;
		}
	}
}

static void	update_x_gun_offset(t_cub *cub)
{
	// Horizontal offset (movement left/right)
	if (cub->p.move_left && cub->obj.offset.x < GUN_OFFSET)
		cub->obj.offset.x += (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else if (cub->p.move_right && cub->obj.offset.x > -GUN_OFFSET)
		cub->obj.offset.x -= (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else
	{
		// ease back toward 0 when no horizontal input
		if (cub->obj.offset.x > 0)
		{
			cub->obj.offset.x -= GUN_OFFSET_SPEED * cub->fps.delta_time;
			if (cub->obj.offset.x < 0)
				cub->obj.offset.x = 0;
		}
		else if (cub->obj.offset.x < 0)
		{
			cub->obj.offset.x += GUN_OFFSET_SPEED * cub->fps.delta_time;
			if (cub->obj.offset.x > 0)
				cub->obj.offset.x = 0;
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
   delta_time = current_time - cub->obj.last_update;
	// Update the timer with the time passed since last frame
	cub->obj.timer += delta_time;
	// Advance frames if enough time has passed
	while (cub->obj.timer >= cub->obj.frame_duration)
	{
		cub->obj.timer -= cub->obj.frame_duration;
		cub->obj.frame = (cub->obj.frame + 1) % cub->obj.sprites_num;
	}
	// Update the last update time
	cub->obj.last_update = current_time;
	// Draw current frame
	if (cub->obj.inspect)
	{
		draw_sprite(cub, &cub->obj.inspect_sprites[cub->obj.frame], 2);
		if (cub->obj.frame == 3)
			cub->obj.inspect = false;
	}
	else
		draw_sprite(cub, &cub->obj.sprites[cub->obj.frame], 2);
}
