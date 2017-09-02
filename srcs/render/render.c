#include "fdf.h"

void            apply_height(t_map *map, double del)
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

void			scale_def(t_map *map)
{
	int			h;
	int			w;

	h = WIN_HEIGHT / map->height;
	w = WIN_WIDTH / map->width;
	if (h > w)
		h = w;
	map->scale = h;
	apply_scale(map, h);
}

void			pose_def(t_render *render)
{

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

void			get_limits(t_map *map)
{
	(void)map;
}

void        apply_matrice(t_render *render, int y, int to)
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

void        dump_lines(t_render *render, int y, int to)
{
	t_point     	**vec;
	int         	x;
	t_point			*o;
	unsigned int	color = 0x00FFFFFF;

	y--;
	o = &render->origin;
	vec = render->map->done;
	if (to >= render->map->height)
		to = render->map->height - 1;
	while (++y < to)
	{
		x = -1;
		while (++x < render->map->width - 1)
		{
			put_line(render->pixs, (int[4]){ o->x + (vec[y] + x)->x, o->y + (vec[y] + x)->y, o->x + (vec[y] + x + 1)->x, o->y + (vec[y] + x + 1)->y }, color);
			put_line(render->pixs, (int[4]){ o->x + (vec[y] + x)->x, o->y + (vec[y] + x)->y, o->x + (vec[y + 1] + x)->x, o->y + (vec[y + 1] + x)->y }, color);
		}
		put_line(render->pixs, (int[4]){ o->x + (vec[y] + x)->x, o->y + (vec[y] + x)->y, o->x + (vec[y + 1] + x)->x, o->y + (vec[y + 1] + x)->y }, color);
	}
	x = -1;
	while (++x < render->map->width - 1)
	{
		put_line(render->pixs, (int[4]){ o->x + (vec[y] + x)->x, o->y + (vec[y] + x)->y, o->x + (vec[y] + x + 1)->x, o->y + (vec[y] + x + 1)->y }, color);
		
	}
}

t_render	*render_get()
{
	static	t_render	render;
	return (&render);
}

t_render    *render_init(t_map *map)
{
	t_render	*render;

	render = render_get();
	render->map = map;
	render->mlx = mlx_init();
	render->win = mlx_new_window(render->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx_key_hook(render->win, key_event, render);	
	mlx_mouse_hook(render->win, key_event, render);	
	mlx_hook(render->win, 0, 0, mouse_event, render);
	if (!(render->img = mlx_new_image(render->mlx, WIN_WIDTH, WIN_HEIGHT)))
	{
		ft_putendl("Can't load texture !");
		exit(1);
	}
	render->pixs = mlx_get_data_addr(render->img, &render->bpx, &render->sl, &render->end);
	scale_def(render->map);
	render->flags = (F_UPROT | F_UPORIGIN);
	return (render);
}

void		render_stop(t_render **render)
{
	t_render	 *r;

	r = *render;
	mlx_destroy_image(r->mlx, r->img);
	mlx_destroy_window(r->mlx, r->win);
	exit(1);
}
