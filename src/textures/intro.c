/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:12:17 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 16:38:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_sprite(t_cub *cub, t_img_texture *t)
{
	t_pointi tex;
	t_pointi screen;
	int      color;
	double   scale_x;
	double   scale_y;

	// Scale factors to match screen resolution exactly
	scale_x = (double)WIDTH  / (double)t->img_width;
	scale_y = (double)HEIGHT / (double)t->img_height;

	screen.y = 0;
	while (screen.y < HEIGHT)
	{
		tex.y = (int)(screen.y / scale_y);
		screen.x = 0;
		while (screen.x < WIDTH)
		{
			tex.x = (int)(screen.x / scale_x);
			color = get_texel(t, tex.x, tex.y);
			if (color != 0xFF000000)
				cub->img.pixels[screen.y * cub->img.pitch + screen.x] = color;
			screen.x++;
		}
		screen.y++;
	}
}

// void	put_centred_sprite(t_cub *cub, t_img_texture *t)
// {
// 	t_pointi	pos;
// 	t_pointi	cord;
// 	int			color;
// 	t_pointi	deplacement;
	
// 	pos = (t_pointi){0, 0};

// 	while (pos.y < t->img_height)
// 	{
// 		pos.x = 0;
// 		cord.y = (pos.y + (HEIGHT / 2) - t->img_height / 2) * cub->img.pitch;
// 		while (pos.x < t->img_width)
// 		{
// 			color = get_texel(t, pos.x, pos.y);
// 			cord.x = pos.x + (WIDTH / 2) - t->img_width / 2;
// 			if (check_screen_edge(cord.x, cord.y / cub->img.pitch) && color != 0xFF000000)
// 				cub->img.pixels[cord.y + cord.x] = color;
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// }

void	put_centred_sprite(t_cub *cub, t_img_texture *t)
{
	t_pointi	pos;
	t_pointi	cord;
	int			color;

	double scale = (double)cub->half_height / 400.0;
	int target_w = t->img_width * scale;
	int target_h = t->img_height * scale;

	pos.y = 0;
	while (pos.y < target_h)
	{
		pos.x = 0;
		cord.y = (pos.y + (HEIGHT / 2) - target_h / 2) * cub->img.pitch;
		while (pos.x < target_w)
		{
			// Map back to texture coordinates
			int tex_x = (pos.x * t->img_width) / target_w;
			int tex_y = (pos.y * t->img_height) / target_h;

			color = get_texel(t, tex_x, tex_y);
			cord.x = pos.x + (WIDTH / 2) - target_w / 2;
			if (check_screen_edge(cord.x, cord.y / cub->img.pitch) && color != 0xFF000000)
				cub->img.pixels[cord.y + cord.x] = color;
			pos.x++;
		}
		pos.y++;
	}
}


int	put_logo(t_cub *cub)
{
	t_img_texture	*t;

	t = &cub->logo_texture;
	t->relative_path = "./textures/logo.xpm";
	if (prepare_sprite_metadata(cub, t) == 1)
		return (EXIT_FAILURE);
	put_centred_sprite(cub, t);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win,
	cub->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

void	put_intro(t_cub *cub)
{
	int	i;
	t_img_texture	*t;
	
	i = 0;
	while (i < INTRO_NUM)
	{
		t = &cub->intro_textures[i];
		put_sprite(cub, t);
		usleep(50000);
		i++;
		mlx_put_image_to_window(cub->mlx, cub->mlx_win,
		cub->img.img_ptr, 0, 0);
	}
}

int	init_intro(t_cub *cub)
{
	int	 i;
	char *idx;
	char *file_name;
	char *path;
	
	i = 0;
	while (i < INTRO_NUM)
	{
		idx = ft_itoa(i);
		file_name = ft_strjoin(PATH, idx);
		path = ft_strjoin(file_name, ".xpm");
		cub->intro_textures[i].relative_path = path;
		if (prepare_sprite_metadata(cub, &cub->intro_textures[i]) == 1)
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
