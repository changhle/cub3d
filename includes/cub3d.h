/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:12:14 by ljeongin          #+#    #+#             */
/*   Updated: 2023/02/04 17:47:00 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <stdio.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 960

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define SPRITE_NUM 400

# define MINI_VOID 0xDD000000
# define MINI_WALL 0x66000000
# define MINI_DOOR 0x66666666
# define MINI_FIELD 0x66FFFFFF
# define MINI_PLAYER 0x66FF6600

typedef struct s_game_data	t_game_data;
typedef struct s_map		t_map;
typedef struct s_mlx		t_mlx;
typedef struct s_coord		t_coord;
typedef struct s_sprite		t_sprite;
typedef struct s_ray		t_ray;
typedef struct s_screen		t_screen;
typedef struct s_minimap	t_minimap;

struct s_game_data
{
	t_map		*map;
	t_mlx		*mlx;
	t_ray		*ray;
	t_sprite	*sprite;
	double		*z_buffer;
	int			engine;
	int			mouse;
	int			door;
	int			x;
	int			y;
};

struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_screen	*screen;
	t_minimap	*minimap;
};

struct s_screen
{
	int		*addr;
	void	*img_ptr;
	int		bpp;
	int		sizel;
	int		endian;
};

struct s_minimap
{
	size_t	magx;
	int		*addr;
	void	*img_ptr;
	int		bpp;
	int		sizel;
	int		endian;
};

enum e_keycode
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	E = 14,
	UP = 126,
	DOWN = 125,
	LEFT = 123,
	RIGHT = 124,
	ONE = 18
};

enum e_event_key
{
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_RELEASE = 3,
	X_EVENT_KEY_EXIT = 17
};

enum e_dir
{
	DIR_W = 1 << 0,
	DIR_A = 1 << 1,
	DIR_S = 1 << 2,
	DIR_D = 1 << 3,
	ROT_LEFT = 1 << 4,
	ROT_RIGHT = 1 << 5
};

void	parse(const char *argv, t_game_data *game_data);

/*
**	window
*/
void	init_mlx(t_game_data *game_data, t_map *map, t_mlx *mlx);
int		mlx_key_press_event(int keycode, t_game_data *game_data);
int		mlx_key_release_event(int keycode, t_game_data *game_data);
int		mlx_loop_hook_event(t_game_data *game_data);
int		exit_event(void *game_data);

/*
**	loop_hook_event
*/
void	raycast(t_coord *coord, t_ray *ray, size_t x);
void	sprite_cast(t_game_data *game_data, t_coord *coord, t_sprite *sprite,
			double z_buffer[]);
void	draw_sprite(t_game_data *game_data, t_sprite *sprite, size_t x);
void	draw_screen(t_game_data *game_data);
void	draw_minimap(t_game_data *game_data, t_minimap *minimap);

int		move_engine(t_game_data *game_data);
void	move_mouse(t_game_data *game_data);
void	move_door(t_game_data *game_data);
void	rotate_left(t_coord *coord);
void	rotate_right(t_coord *coord);

void	move_forward(t_coord *coord);
void	move_backward(t_coord *coord);
void	move_left(t_coord *coord);
void	move_right(t_coord *coord);

#endif
