#include "cub3d.h"
#include "map.h"

void	move_sprite(t_game_data *game_data)
{
	static int	count = 0;

	count++;
	if (count == 40)
	{
		game_data->map->texture->sp = game_data->map->texture->s_2;
		draw_screen(game_data);
	}
	else if (count == 80)
	{
		game_data->map->texture->sp = game_data->map->texture->s_1;
		draw_screen(game_data);
		count = 0;
	}
}