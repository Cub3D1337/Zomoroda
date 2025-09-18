/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:02:26 by wahmane           #+#    #+#             */
/*   Updated: 2025/09/18 17:12:05 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSING_H
# define PARSING_H



typedef struct s_config {
    char *no_texture, *so_texture, *we_texture, *ea_texture;
    int   floor_rgb[3];
    int   ceil_rgb[3];
    char **map;
    int   map_h, map_w;
    int   player_x, player_y;
    char  player_dir;
} t_config;

typedef struct s_vec
{
    char    **data;
    int     size;
    int     cap;
}   t_vec;

int	open_file(int ac, char **av, int *fd);
int	handle_invalid_line(char *line, int fd);
int	handle_map_line(char *line, t_config *cfg, int *seen_map, int fd);
int	handle_line_before_map(char *line, t_config *cfg, int *seen_map, int fd);
int parsing(int ac, char **av, t_config *cfg);

int	skip_spaces(char *line, int *i);
int	parse_identifier_line(char *line, t_config *cfg, int i);
int	parse_color_line(char *line, t_config *cfg, int i);
int	parse_line_before_map(char *line, t_config *cfg);
int	is_inside(int x, int y, const t_config *cfg);

int	push_line(t_vec *raw, char *line);
int	read_map_lines(int fd, t_vec *raw);
int	collect_map(int fd, char *first_line, t_config *cfg);
int	check_neighbors(t_config *cfg);
int	validate_player_and_close(t_config *cfg);

char	*trim_texture_path(const char *path);
int	validate_texture_file(const char *path, const char *id);
int	set_texture(char **slot, const char *path_start, const char *id);
int check_player_spawn(t_config *cfg, int *px, int *py);
int	check_map_edges(t_config *cfg);

int	error(const char *msg);
void	vec_init(t_vec *v);
int	vec_push(t_vec *v, char *line);
void	vec_free(t_vec *v);
int	rstrip_newline(char *s);

void	init_config(t_config *cfg);
void	free_config(t_config *cfg);
int	check_extension(char **av);
int	is_all_space(const char *s);
void	free_split(char **arr);

int	read_int(const char **s, int *out);
int	parse_rgb(const char *s, int out[3]);
int	is_map_line(const char *line);
void	fill_row(char *dst, char *src, int w);
int	build_rect_map(t_config *cfg, t_vec *raw);

int	check_cell_neighbors(t_config *cfg, int x, int y);
int	check_row(t_config *cfg, int y, int x);
int	check_cell_player(t_config *cfg, int x, int y, int *pc);
int	check_row_player(t_config *cfg, int y, int x, int *pc);

int	validate_once_all_present(const t_config *cfg);
int	check_column_top_bottom(t_config *cfg, int x);
int	check_row_sides(t_config *cfg, int y);
int check_gate(t_config *cfg, int x, int y);

#endif