#include "fdf.h"

t_render		*render_get()
{
	static	t_render	render;
	return (&render);
}

void			apply_scale(t_map *map, double del)
{
	int     x;
	int     y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->data[y][x].x *= del;
			map->data[y][x].y *= del;
			map->data[y][x].z *= del;
		}
	}
}

void			apply_height(t_map *map, double del)
{
	int     x;
	int     y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			(map->data[y] + x)->z *= del;
		}
	}
}

void			apply_matrice(t_render *render, int y, int to)
{
	t_vec3      **vec;
	t_point     **done;
	int         x;

	rot_update(&render->rot);
	done = render->map->done;
	vec = render->map->data;
	y--;
	while (++y < to)
	{
		x = -1;
		while (++x < render->map->width)
		{
			rot_apply(&render->rot, (vec[y] + x), (done[y] + x));
		}
	}
	render->flags &= ~(F_UPROT | F_UPORIGIN);
}

int			get_col(int	z)
{
	while (z > 40)
		z >>= 2;
	if (z <= 1)
		return (0x000c66f7);
	else if (z <= 3)
		return (0xe005ff42);
	else if (z <= 10)
		return (0x000da519);
	else if (z <= 30)
		return (0x00704f08);
	else
		return (0x00e0e0e0);
}