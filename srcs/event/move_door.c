#include "cub3d.h"
#include "map.h"

int	move_door(t_coord *coord)
{
	int	dist;
	int	door;
	int	x;
	int	y;

	dist = 1;
	door = TRUE;
	x = (int)coord->pos_x;
	y = (int)coord->pos_y;
	while (dist < 3)
	{
		if (coord->dir_y > 0.9 && coord->maparr[y + dist][x] == DOOR_C)
			coord->maparr[y + dist][x] = DOOR_O;
		else if (coord->dir_y > 0.9 && coord->maparr[y + dist][x] == DOOR_O)
			coord->maparr[y + dist][x] = DOOR_C;
		else if (coord->dir_y < -0.9 && coord->maparr[y - dist][x] == DOOR_C)
			coord->maparr[y - dist][x] = DOOR_O;
		else if (coord->dir_y < -0.9 && coord->maparr[y - dist][x] == DOOR_O)
			coord->maparr[y - dist][x] = DOOR_C;
		else if (!door && dist == 2)
			door = FALSE;
		dist++;
	}
	return (door);
}
