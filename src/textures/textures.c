/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:48:21 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/24 22:54:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	get_tex(t_cub *cub,
	t_tex_ctx *ctx, t_texture_data *data)
{
	t_pointi	cord;

	cord.y = (ctx->result.map_pos.y);
	cord.x = (ctx->result.map_pos.x);
	if (cub->map.array[cord.y][cord.x] == 'D')
		data->tex = &cub->textures[DOOR];
	else if (ctx->result.side == VERTICAL && ctx->result.dir_step.y == 1)
		data->tex = &cub->textures[NORTH];
	else if (ctx->result.side == VERTICAL && ctx->result.dir_step.y == -1)
		data->tex = &cub->textures[SOUTH];
	else if (ctx->result.side == HORIZONTAL && ctx->result.dir_step.x == 1)
		data->tex = &cub->textures[EAST];
	else if (ctx->result.side == HORIZONTAL && ctx->result.dir_step.x == -1)
		data->tex = &cub->textures[WEST];
}

static void	setup(t_cub *cub, t_tex_ctx *ctx, t_texture_data *data)
{
	if (ctx->result.side == HORIZONTAL)
		data->wall_x = ctx->result.hit_point.y / BLOCK_SIZE;
	else
		data->wall_x = ctx->result.hit_point.x / BLOCK_SIZE;
	get_tex(cub, ctx, data);
	data->wall_x -= floor(data->wall_x);
	data->tex_cord.x = (int)(data->wall_x * data->tex->img_w);
	if ((ctx->result.side == HORIZONTAL && ctx->ray_dir.x < 0)
		|| (ctx->result.side == VERTICAL && ctx->ray_dir.y > 0))
	{
		data->tex_cord.x = data->tex->img_w - data->tex_cord.x - 1;
	}
	data->step = (double)data->tex->img_h / ctx->line_height;
	data->tex_pos = (ctx->start_y - cub->p.horizon
			+ (ctx->line_height / 2.0)) * data->step;
}

void	mapping_textures(t_cub *cub, t_tex_ctx *ctx)
{
	t_texture_data	data;

	setup(cub, ctx, &data);
	while (ctx->start_y <= ctx->end_y)
	{
		data.tex_cord.y = (int)data.tex_pos;
		if (data.tex_cord.y < 0)
			data.tex_cord.y = 0;
		else if (data.tex_cord.y >= data.tex->img_h)
			data.tex_cord.y = data.tex->img_h - 1;
		data.color = get_texel(data.tex, data.tex_cord.x, data.tex_cord.y);
		if (check_minimap_edge(cub, ctx->x, ctx->start_y))
		{
			cub->img.pixels[ctx->start_y * cub->img.pitch + ctx->x]
				= data.color;
		}
		data.tex_pos += data.step;
		ctx->start_y++;
	}
}
