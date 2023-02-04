/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:57:51 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:57:53 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

#include "mlx.h"
#include "libft.h"
#include "macro.h"

void	error_exit_with_str(char *str);

static void	init_game_data(t_game_data *game_data)
{
	game_data->map = ft_malloc(1, sizeof(t_map));
	game_data->mlx = ft_malloc(1, sizeof(t_mlx));
	game_data->mlx->mlx_ptr = mlx_init();
	game_data->engine = 0;
	game_data->mouse = -1;
}

int	main(int argc, char **argv)
{
	t_game_data	game_data;

	if (argc != 2)
		error_exit_with_str("cud3D: invalid number of argument");
	init_game_data(&game_data);
	parse(argv[1], &game_data);
	init_mlx(&game_data, game_data.map, game_data.mlx);
	mlx_hook(game_data.mlx->win_ptr, X_EVENT_KEY_PRESS, 1L << 0, \
				&mlx_key_press_event, &game_data);
	mlx_hook(game_data.mlx->win_ptr, X_EVENT_KEY_RELEASE, 1L << 1, \
				&mlx_key_release_event, &game_data);
	mlx_hook(game_data.mlx->win_ptr, X_EVENT_KEY_EXIT, 1L << 2, \
				&exit_event, &game_data);
	mlx_loop_hook(game_data.mlx->mlx_ptr, &mlx_loop_hook_event, &game_data);
	mlx_loop(game_data.mlx->mlx_ptr);
	return (EXIT_SUCCESS);
}
