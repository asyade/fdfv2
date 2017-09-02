#ifndef STRUCTS_H
# define STRUCTS_H

# include <mlx.h>
# include "vector.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_tline
{
	int			x;
	int			y;
	int			dy;
	int			dx;
	int			xinc;
	int			yinc;
	int			cumul;
}				t_tline;

typedef struct		s_map
{
	t_vec3			**data;
	t_point			**done;
	t_point			**old;
	int				width;
	int				height;
	int				error;
	int				scale;
}					t_map;

typedef struct		s_render
{
	int				fill;
	int				sl;
	int				end;
	int				bpx;
	char			*pixs;
	unsigned int	**lines;
	t_point			origin;
	int				ratio;
	t_map			*map;
	void			*win;
	void			*mlx;
	void			*img;
	t_rotmatrice	rot;
	int				flags;
	int				loadId;
	pthread_mutex_t	thCounterLock;
	int				thCount;
	unsigned int	startclock;
	unsigned int	deltaclock;
	pthread_mutex_t	lockMutex;
	pthread_cond_t	lock;
	pthread_mutex_t	drawMutex;
	pthread_cond_t	draw;
	pthread_mutex_t	coordsMutex;
}					t_render;

typedef struct		s_thrender
{
	pthread_t		thread;
	t_point			limits;
	t_render		*render;
}					t_thrender;

#endif
