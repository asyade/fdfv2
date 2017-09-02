#include "fdf.h"

# define	TCOUNT 4//4 render/4 draw a voir sur les mac si on envoie pas plus de threads
t_thrender	threads[TCOUNT];
t_thrender	rndthreads[TCOUNT];

void		*thread_render(void *av)
{
	t_thrender	*r;

	if (!(r = (t_thrender *)av))
		return (av);
	while (1)
	{
		pthread_mutex_lock(&r->render->lockMutex);
		pthread_cond_wait(&r->render->lock, &r->render->lockMutex);
		pthread_mutex_unlock(&r->render->lockMutex);
		apply_matrice(r->render, r->limits.x, r->limits.y);	
		pthread_mutex_lock(&r->render->thCounterLock);
		r->render->thCount--;
		pthread_mutex_unlock(&r->render->thCounterLock);
	}
	return (av);
}

void		*thread_render_draw(void *av)
{
	t_thrender	*r;

	if (!(r = (t_thrender *)av))
		return (av);
	while (1)
	{
		pthread_mutex_lock(&r->render->drawMutex);
		pthread_cond_wait(&r->render->draw, &r->render->drawMutex);
		pthread_mutex_unlock(&r->render->drawMutex);
		dump_lines(r->render, r->limits.x, r->limits.y);		
		pthread_mutex_lock(&r->render->thCounterLock);
		r->render->thCount--;
		pthread_mutex_unlock(&r->render->thCounterLock);
	}
	return (av);
}

void		threads_exec(t_render *render)
{
	t_point		**tmp;
	render->thCount = TCOUNT * 2;
	pthread_mutex_lock(&render->drawMutex);
	pthread_cond_broadcast(&render->draw);
	pthread_mutex_unlock(&render->drawMutex);
	pthread_mutex_lock(&render->lockMutex);
	pthread_cond_broadcast(&render->lock);
	pthread_mutex_unlock(&render->lockMutex);
	while (render->thCount > 0)
		;
	tmp = render->map->done;
	render->map->done = render->map->old;
	render->map->old = tmp;
	render->flags |= F_OLDREADY;
}

void		threads_init(t_render *render)
{
	int		i;
	int		d;

	i = TCOUNT;
	d = render->map->height / TCOUNT;
	while (i--)
	{
		threads[i].limits.x = d * i;
		threads[i].limits.y = d * (i + 1);
		threads[i].render = render;	
		if (pthread_create(&threads[i].thread, NULL, thread_render, &threads[i]) != 0)
		{
			ft_putendl("Can't load threads exit");
			exit(1);
		}		
	}
	threads[TCOUNT - 1].limits.y += render->map->height - (d * TCOUNT);
}

void		render_def(t_render *render)
{
	int		prop;
	int		divi;

	render->flags |= F_UPROT | F_REFRESH | F_UPORIGIN;
	divi = render->map->width;
	prop = WIN_WIDTH / divi;
	apply_scale(render->map, prop);	
}

int			render_apply(t_render *render)
{
	ft_bzero(render->pixs, WIN_HEIGHT * WIN_WIDTH * 4);
	apply_matrice(render, 0, render->map->height);
	dump_lines(render, 0, render->map->height);
	//mlx_clear_window(render->mlx, render->win);
	mlx_put_image_to_window(render->mlx, render->win, render->img, 0, 0);
	return (0);
}

void		render_loop(t_render *render)
{
	//if (render->map->height >= TCOUNT)	
	//	threads_init(render);
	render->flags = 0xFFFFFFFF;
	mlx_expose_hook(render->win, render_apply, render);
	mlx_loop(render->mlx);
}
