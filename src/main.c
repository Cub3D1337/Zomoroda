/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:48:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 14:22:24 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

void print_config(const t_config *cfg)
{
	if (!cfg)
		return;

	printf("Textures:\n");
	printf("  NO: %s\n", cfg->no_texture ? cfg->no_texture : "(null)");
	printf("  SO: %s\n", cfg->so_texture ? cfg->so_texture : "(null)");
	printf("  WE: %s\n", cfg->we_texture ? cfg->we_texture : "(null)");
	printf("  EA: %s\n", cfg->ea_texture ? cfg->ea_texture : "(null)");

	printf("Colors:\n");
	printf("  Floor RGB: %d, %d, %d\n", cfg->floor_rgb[0], cfg->floor_rgb[1], cfg->floor_rgb[2]);
	printf("  Ceiling RGB: %d, %d, %d\n", cfg->ceil_rgb[0], cfg->ceil_rgb[1], cfg->ceil_rgb[2]);

	printf("Map size: %d x %d\n", cfg->map_h, cfg->map_w);
	printf("Map:\n");
	if (cfg->map)
	{
		for (int y = 0; y < cfg->map_h; y++)
			printf("  %s\n", cfg->map[y]);
	}
	else
		printf("  (null)\n");
	printf("Player:\n");
	printf("  Position: (%d, %d)\n", cfg->player_x, cfg->player_y);
	printf("  Direction: %c\n", cfg->player_dir);
}

int play_music_loop(ma_engine *engine, ma_sound *sound, const char *filename)
{
    ma_result result;

    // Initialize audio engine
    result = ma_engine_init(NULL, engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine\n");
        return -1;
    }

    // Initialize sound from file (looping)
    result = ma_sound_init_from_file(engine, filename, MA_SOUND_FLAG_LOOPING, NULL, NULL, sound);
    if (result != MA_SUCCESS) {
        printf("Failed to load sound\n");
        ma_engine_uninit(engine);
        return -1;
    }

    // Start playing
    result = ma_sound_start(sound);
    if (result != MA_SUCCESS) {
        printf("Failed to start sound\n");
        ma_sound_uninit(sound);
        ma_engine_uninit(engine);
        return -1;
    }

    return 0;
}

void stop_music(ma_engine *engine, ma_sound *sound)
{
    ma_sound_uninit(sound);
    ma_engine_uninit(engine);
}



int	main(int ac, char **av)
{
	t_cub		cub;
	t_config	cfg;
	ma_engine  engine;
	ma_sound   sound;

	//TODO: Some map model can't be parsed
	//TODO: Door Issue

    // Start looping music
    if (play_music_loop(&engine, &sound, "zomoroda.mp3") != 0)
        printf("Music failed to start\n");
	
	init_config(&cfg);
	if (parsing(ac, av, &cfg) == 0)
		return (EXIT_FAILURE);
	print_config(&cfg);
	init_cub(&cub, &cfg);
	init_textures(&cub, &cfg);
	init_sprites(&cub);
	init_image_buffer(&cub);
	init_map_image_buffer(&cub);
	init_events(&cub);
	mlx_loop(cub.mlx);

	stop_music(&engine, &sound);
	ft_exit(&cub);
	free_config(&cfg);
	return (EXIT_SUCCESS);
}
