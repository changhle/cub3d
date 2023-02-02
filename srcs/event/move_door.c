#include "cub3d.h"
#include "map.h"

void	move_door(t_coord *coord)
{
	int	dist;
	int	pos_x;
	int	pos_y;

	dist = 1;
	pos_x = (int)coord->pos_x;
	pos_y = (int)coord->pos_y;
	while (dist < 3)
	{
		if (coord->dir_y > 0.9
			&& coord->maparr[pos_y + dist][pos_x] == DOOR_C)
			coord->maparr[pos_y + dist][pos_x] = DOOR_O;
		else if (coord->dir_y > 0.9
			&& coord->maparr[pos_y + dist][pos_x] == DOOR_O)
			coord->maparr[pos_y + dist][pos_x] = DOOR_C;
		if (coord->dir_y < -0.9
			&& coord->maparr[pos_y - dist][pos_x] == DOOR_C)
			coord->maparr[pos_y - dist][pos_x] = DOOR_O;
		else if (coord->dir_y < -0.9
			&& coord->maparr[pos_y - dist][pos_x] == DOOR_O)
			coord->maparr[pos_y - dist][pos_x] = DOOR_C;
		dist++;
	}
}