/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:56:32 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:56:33 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parse.h"

#include "libft.h"
#include "macro.h"

static t_bool	is_identifier(char *identifier)
{
	return (ft_iseq(identifier, "NO")
		|| ft_iseq(identifier, "EA")
		|| ft_iseq(identifier, "WE")
		|| ft_iseq(identifier, "SO")
		|| ft_iseq(identifier, "DO")
		|| ft_iseq(identifier, "S1")
		|| ft_iseq(identifier, "S2")
		|| ft_iseq(identifier, "F")
		|| ft_iseq(identifier, "C"));
}

char	**parse_texture_data(char *line)
{
	char	**strv;
	char	*line_without_nl;

	line_without_nl = ft_strtrim(line, "\n");
	if (*line_without_nl == '\0')
	{
		ft_free((void **)&line_without_nl);
		return (NULL);
	}
	strv = ft_split(line_without_nl, ' ');
	ft_free((void **)&line_without_nl);
	if (strv[2] || !is_identifier(strv[0]))
		error_exit_with_str("mapfile: has invalid element");
	return (strv);
}
