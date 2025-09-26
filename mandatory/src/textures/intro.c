/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:12:17 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/26 22:31:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_sprite(t_cub *cub, t_img_texture *t)
{
	t_pointd	scaled;
	t_sprite	a;

	scaled.x = (double)WIDTH / (double)t->img_w;
	scaled.y = (double)HEIGHT / (double)t->img_h;
	a.pos = (t_pointi){0, 0};
	while (a.pos.y < HEIGHT)
	{
		a.tex.y = (int)(a.pos.y / scaled.y);
		a.pos.x = 0;
		while (a.pos.x < WIDTH)
		{
			a.tex.x = (int)(a.pos.x / scaled.x);
			a.color = get_texel(t, a.tex.x, a.tex.y);
			if (a.color != 0xFF000000)
				cub->img.pixels[a.pos.y * cub->img.pitch + a.pos.x] = a.color;
			a.pos.x++;
		}
		a.pos.y++;
	}
}

static void	put_centred_sprite(t_cub *cub, t_img_texture *t)
{
	t_sprite	a;

	a.scaled.x = t->img_w * cub->scale;
	a.scaled.y = t->img_h * cub->scale;
	a.pos.y = 0;
	while (a.pos.y < a.scaled.y)
	{
		a.pos.x = 0;
		a.cord.y = (a.pos.y + (HEIGHT / 2) - a.scaled.y / 2) * cub->img.pitch;
		a.tex.y = (a.pos.y * t->img_h) / a.scaled.y;
		while (a.pos.x < a.scaled.x)
		{
			a.tex.x = (a.pos.x * t->img_w) / a.scaled.x;
			a.color = get_texel(t, a.tex.x, a.tex.y);
			a.cord.x = a.pos.x + (WIDTH / 2) - a.scaled.x / 2;
			if (check_screen_edge(a.cord.x, a.cord.y / cub->img.pitch)
				&& a.color != 0xFF000000)
				cub->img.pixels[a.cord.y + a.cord.x] = a.color;
			a.pos.x++;
		}
		a.pos.y++;
	}
}

int	put_logo(t_cub *cub)
{
	t_img_texture	*t;

	if (cub->logo_texture.img_ptr)
		mlx_destroy_image(cub->mlx, cub->logo_texture.img_ptr);
	t = &cub->logo_texture;
	t->relative_path = cub->intro.logo_path;
	if (prepare_sprite_metadata(cub, t) == 1)
		return (EXIT_FAILURE);
	put_centred_sprite(cub, t);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win,
		cub->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

int	put_intro(t_cub *cub)
{
	t_img_texture	*t;
	double			now;

	now = get_time_ms();
	if (cub->intro.intro_index >= INTRO_NUM)
	{
		cub->intro.intro_done = true;
		return (EXIT_SUCCESS);
	}
	if (now - cub->intro.last_time < 95)
		return (EXIT_SUCCESS);
	cub->intro.last_time = now;
	t = &cub->intro.intro_textures[cub->intro.intro_index];
	put_sprite(cub, t);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win,
		cub->img.img_ptr, 0, 0);
	cub->intro.intro_index++;
	return (EXIT_SUCCESS);
}

int	init_intro(t_cub *cub)
{
	int		i;
	char	*idx;
	char	*file_name;
	char	*path;

	i = 0;
	while (i < INTRO_NUM)
	{
		idx = ft_itoa(i);
		file_name = ft_strjoin(cub->intro.intro_path, idx);
		path = ft_strjoin(file_name, ".xpm");
		cub->intro.intro_textures[i].relative_path = path;
		if (prepare_sprite_metadata(cub, &cub->intro.intro_textures[i]) == 1)
		{
			free(idx);
			free(file_name);
			free(path);
			return (EXIT_FAILURE);
		}
		free(idx);
		free(file_name);
		free(path);
		i++;
	}
	return (EXIT_SUCCESS);
}
