/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:12:28 by ljeongin          #+#    #+#             */
/*   Updated: 2022/11/02 09:12:30 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parse.h"

#include "libft.h"

static void	check_rgb_data(char *str)
{
	size_t	comma_cnt;

	comma_cnt = 0;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ',')
			error_exit_with_str("mapfile: element: has invalid RGB value");
		if (*str == ',')
			comma_cnt++;
		str++;
	}
	if (comma_cnt != 2)
		error_exit_with_str("mapfile: element: has invalid RGB value");
}

static char	**split_rgb_data(char *str)
{
	char	**strarr;
	size_t	i;

	check_rgb_data(str);
	strarr = ft_split(str, ',');
	i = 0;
	while (strarr[i])
	{
		if (ft_strlen(strarr[i]) > 3)
			error_exit_with_str("mapfile: element: has invalid RGB value");
		i++;
	}
	if (i != 3)
		error_exit_with_str("mapfile: element: has invalid RGB value");
	return (strarr);
}

static int	get_rgb_data(char *str)
{
	int		rgb;
	int		val;
	size_t	i;
	char	**rgb_data;

	rgb = 0;
	i = 0;
	rgb_data = split_rgb_data(str);
	while (i < 3)
	{
		val = ft_atoi(rgb_data[i]);
		if (val > 255)
			error_exit_with_str("mapfile: element: has invalid RGB value");
		rgb <<= 8;
		rgb |= val;
		i++;
	}
	free_strv(rgb_data);
	return (rgb);
}

void	get_texture(char **texture_data, t_map *map, t_filepath *filepath)
{
	if (ft_iseq(texture_data[0], "NO"))
		filepath->n = ft_strdup(texture_data[1]);
	else if (ft_iseq(texture_data[0], "WE"))
		filepath->e = ft_strdup(texture_data[1]);
	else if (ft_iseq(texture_data[0], "EA"))
		filepath->w = ft_strdup(texture_data[1]);
	else if (ft_iseq(texture_data[0], "SO"))
		filepath->s = ft_strdup(texture_data[1]);
	else if (ft_iseq(texture_data[0], "F"))
		map->texture->floor = get_rgb_data(texture_data[1]);
	else if (ft_iseq(texture_data[0], "C"))
		map->texture->ceil = get_rgb_data(texture_data[1]);
}
