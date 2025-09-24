/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:55:40 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 21:42:50 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_sprite(t_cub *cub, t_img_texture *t, double s)
{
	t_sprite	a;

	if (!t || s <= 0.0)
		return ;
	a.scaled = (t_pointi){(int)(t->img_w * s), (int)(t->img_h * s)};
	a.deplacement = (t_pointi){cub->half_width - (a.scaled.x / 2),
		HEIGHT - a.scaled.y};
	a.pos.y = 0;
	while (a.pos.y < a.scaled.y)
	{
		a.pos.x = 0;
		a.tex.y = (int)((double)a.pos.y / s);
		a.cord.y = (a.pos.y++ + a.deplacement.y + cub->obj.offset.y + 50)
			* cub->img.pitch;
		while (a.pos.x < a.scaled.x)
		{
			a.tex.x = (int)((double)a.pos.x / s);
			a.cord.x = a.pos.x++ + a.deplacement.x + cub->obj.offset.x;
			a.color = get_texel(t, a.tex.x, a.tex.y);
			if (check_screen_edge(a.cord.x, a.cord.y / cub->img.pitch)
				&& a.color != 0xFF000000)
				cub->img.pixels[a.cord.y + a.cord.x] = a.color;
		}
	}
}

static void	update_y_gun_offset(t_cub *cub)
{
	if (cub->p.move_up && cub->obj.offset.y < GUN_OFFSET)
		cub->obj.offset.y += (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else if (cub->p.move_down && cub->obj.offset.y > -GUN_OFFSET)
		cub->obj.offset.y -= (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else
	{
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
	if (cub->p.move_left && cub->obj.offset.x < GUN_OFFSET)
		cub->obj.offset.x += (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else if (cub->p.move_right && cub->obj.offset.x > -GUN_OFFSET)
		cub->obj.offset.x -= (int)(GUN_OFFSET_SPEED * cub->fps.delta_time);
	else
	{
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
	double	scale;

	update_y_gun_offset(cub);
	update_x_gun_offset(cub);
	scale = (double)cub->half_height / 200.0;
	current_time = get_time_ms() / 1000.0;
	delta_time = current_time - cub->obj.last_update;
	cub->obj.timer += delta_time;
	while (cub->obj.timer >= cub->obj.frame_duration)
	{
		cub->obj.timer -= cub->obj.frame_duration;
		cub->obj.frame = (cub->obj.frame + 1) % cub->obj.sprites_num;
	}
	cub->obj.last_update = current_time;
	if (cub->obj.inspect)
	{
		draw_sprite(cub, &cub->obj.inspect_sprites[cub->obj.frame], scale);
		if (cub->obj.frame == 3)
			cub->obj.inspect = false;
	}
	else
		draw_sprite(cub, &cub->obj.sprites[cub->obj.frame], scale);
}
