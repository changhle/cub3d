/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:54:13 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 15:42:32 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>

typedef struct s_game_data	t_game_data;
typedef struct s_map		t_map;
typedef enum e_maparr		t_maparr;
typedef struct s_filepath	t_filepath;
typedef struct s_coord		t_coord;

typedef struct s_buffer		t_buffer;

struct s_buffer
{
	char	**buf;
	size_t	size;
	size_t	cap;
};

void	error_exit_with_str(char *str);
void	perror_exit(char *str);

void	free_strv(char **strv);

void	init_texture(int fd, t_game_data *game_data);
char	**parse_texture_data(char *line);
void	get_texture(char **texture_data, t_map *map, t_filepath *filepath);

void	copy_map_from_buf(t_buffer *buffer, t_coord *coord);
void	check_map(t_coord *coord);
void	check_vertical_line(size_t width, size_t height, t_maparr **maparr);
void	check_horizontal_line(size_t width, size_t height, t_maparr **maparr);
void	init_map_content(int fd, t_map *map);
void	init_coord_value(t_coord *coord);
int		sprite_cnt(t_map *map);
void	init_sprite_map(t_game_data *game_data);

void	init_buffer(t_buffer *buffer);
void	append_buffer(t_buffer *buffer, char *str);
void	clear_buffer(t_buffer *buffer);

#endif
