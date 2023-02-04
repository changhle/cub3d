/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:56:25 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:56:26 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"
#include "parse.h"

#include "mlx.h"
#include "libft.h"
#include "get_next_line.h"

void	error_exit_with_str(char *str);

void	free_strv(char **strv)
{
	size_t	i;

	i = 0;
	while (strv[i])
		ft_free((void **)&strv[i++]);
	ft_free((void **)&strv);
}

static void	load_texture_targetfile(t_mlx *mlx, t_image *img, char *path)
{
	int	width;
	int	height;

	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &width, &height);
	if (!img->img_ptr)
		error_exit_with_str("texture: cannot open targetfile");
	if (width != TEXTURE_WIDTH || height != TEXTURE_HEIGHT)
		error_exit_with_str("texture: must have 64 x 64 pixels");
	img->addr = (int *)mlx_get_data_addr(
			img->img_ptr, &img->bpp, &img->sizel, &img->endian
			);
}

static void	get_texture_targetfile(t_game_data *game_data, t_filepath *filepath)
{
	load_texture_targetfile(
		game_data->mlx, game_data->map->texture->n, filepath->n
		);
	load_texture_targetfile(
		game_data->mlx, game_data->map->texture->e, filepath->e
		);
	load_texture_targetfile(
		game_data->mlx, game_data->map->texture->w, filepath->w
		);
	load_texture_targetfile(
		game_data->mlx, game_data->map->texture->s, filepath->s
		);
	load_texture_targetfile(
		game_data->mlx, game_data->map->texture->d, filepath->d
		);
	load_texture_targetfile(
		game_data->mlx, game_data->map->texture->s_1, filepath->s_1
		);
	load_texture_targetfile(
		game_data->mlx, game_data->map->texture->s_2, filepath->s_2
		);
	game_data->map->texture->sp = game_data->map->texture->s_1;
}

static void	free_filepath(t_filepath *filepath)
{
	ft_free((void **)&filepath->n);
	ft_free((void **)&filepath->e);
	ft_free((void **)&filepath->w);
	ft_free((void **)&filepath->s);
	ft_free((void **)&filepath->d);
	ft_free((void **)&filepath->s_1);
	ft_free((void **)&filepath->s_2);
}

void	init_texture(int fd, t_game_data *game_data)
{
	char		*line;
	char		**texture_data;
	size_t		cnt;
	t_filepath	filepath;

	cnt = 0;
	while (cnt < 9)
	{
		line = get_next_line(fd);
		if (!line)
			error_exit_with_str("mapfile: has incomplete element");
		texture_data = parse_texture_data(line);
		if (texture_data)
		{
			get_texture(texture_data, game_data->map, &filepath);
			free_strv(texture_data);
			cnt++;
		}
		ft_free((void **)&line);
	}
	get_texture_targetfile(game_data, &filepath);
	free_filepath(&filepath);
}
