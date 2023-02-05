/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast_bubble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:57:42 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 15:35:04 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	sort_sprite(int order[], double distance[], t_sprite *sprite)
{
	int		i;
	int		j;
	int		tmp_int;
	double	tmp_double;

	i = sprite->sprite_size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (distance[j] < distance[j + 1])
			{
				tmp_double = distance[j];
				distance[j] = distance[j + 1];
				distance[j + 1] = tmp_double;
				tmp_int = order[j];
				order[j] = order[j + 1];
				order[j + 1] = tmp_int;
			}
			j++;
		}
		i--;
	}
}
