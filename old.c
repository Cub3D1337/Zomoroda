

// // utils.c
// void free_split(char **arr)
// {
//     int i = 0;
//     if (!arr) return ;
//     while (arr[i])
//         free(arr[i++]);
//     free(arr);
// }

// // map.c
// void parse_map(char *line, t_config *cfg)
// {
//     // For now, just store or skip
//     (void)line;
//     (void)cfg;
//     // TODO: implement collecting map lines
// }

// // parsing.c (or validate.c)
// void validate_config(t_config *cfg)
// {
//     if (!cfg->no_texture || !cfg->so_texture ||
//         !cfg->we_texture || !cfg->ea_texture)
//     {
//         fdprintf(2, "Error\nMissing texture path\n");
//         exit(EXIT_FAILURE);
//     }
//     // Add more checks (colors set, one spawn, map closed...)
// }

// int is_map_line(char *line)
// {
//     int i = 0;
//     while (line[i])
//     {
//         if (!ft_strchr(" 01NSEW", line[i]))
//             return (0);
//         i++;
//     }
//     return (1);
// }

// void parse_color(char *str, int *color)
// {
//     char **rgb = ft_split(str, ',');
//     int i = 0;

//     while (i < 3)
//     {
//         color[i] = ft_atoi(rgb[i]);
//         if (color[i] < 0 || color[i] > 255)
//         {
//             fdprintf(2, "Error\nInvalid RGB color\n");
//             exit(1);
//         }
//         i++;
//     }
//     free_split(rgb);
// }

// void parse_line(char *line, t_config *cfg)
// {
//     char **tokens;

//     // Skip empty lines
//     if (*line == '\n' || *line == '\0')
//         return ;

//     tokens = ft_split(line, ' '); // split by space

//     if (ft_strncmp(tokens[0], "NO", 2) == 0)
//         cfg->no_texture = ft_strdup(tokens[1]);
//     else if (ft_strncmp(tokens[0], "SO", 2) == 0)
//         cfg->so_texture = ft_strdup(tokens[1]);
//     else if (ft_strncmp(tokens[0], "WE", 2) == 0)
//         cfg->we_texture = ft_strdup(tokens[1]);
//     else if (ft_strncmp(tokens[0], "EA", 2) == 0)
//         cfg->ea_texture = ft_strdup(tokens[1]);
//     else if (ft_strncmp(tokens[0], "F", 1) == 0)
//         parse_color(tokens[1], cfg->floor_color);
//     else if (ft_strncmp(tokens[0], "C", 1) == 0)
//         parse_color(tokens[1], cfg->ceiling_color);
//     else
//         parse_map(line, cfg); // if not identifier, assume it's part of map

//     free_split(tokens);
// }

// int read_file(char *filename, t_config *cfg)
// {
//     int fd = open(filename, O_RDONLY);
//     char *line;

//     if (fd < 0)
//     {
//         fdprintf(2, "Error\nCould not open file\n");
//         return (0);
//     }
//     while ((line = get_next_line(fd)))
//     {
//         parse_line(line, cfg);
//         free(line);
//     }
//     close(fd);
//     return (1);
// }

// int check_extention(char **av)
// {
//     char *ext = ".cub";
//     int i = ft_strlen(av[1]) - 1;
//     int j = 3;

//     while (j >= 0)
//     {
//         if (av[1][i] != ext[j])
//         {
//             fdprintf(STDERR_FILENO,"The extinction incorrect (.cub)");
//             return (0);
//         }
//         i--;
//         j--;
//     }
//     return (1);
// }

// int parsing(int ac, char **av, t_config *cfg)
// {
//     if (ac != 2)
//         return (fdprintf(2, "Error\nWrong number of arguments\n"), 0);
//     if (!check_extention(av))
//         return (0);
//     if (!read_file(av[1], cfg))
//         return (0);
//     validate_config(cfg);
//     return (1);
// }


//! Draw Whole MiniMap
// void	draw_map(t_cub *cub)
// {
// 	t_pointi	pos;
// 	int			color;
// 	unsigned int	*pixels;
// 	unsigned int	pitch;

// 	pixels = (unsigned int *) cub->map_img.img_pixels_ptr;
// 	pitch = cub->map_img.line_length / sizeof(unsigned int);	

// 	pos.y = 0;
// 	while (pos.y < cub->map.minimap_height)
// 	{
// 		pos.x = 0;
// 		while (pos.x < cub->map.minimap_width)
// 		{
// 			color = pixels[(int)pos.y * pitch + (int)pos.x];
// 			put_pixel(cub, pos.x, pos.y, color);
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// }
