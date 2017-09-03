#include "fdf.h"

void        put_pix(char *img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	(void)img;
	(void)color;
	*((unsigned int *)(img) + x + (y * WIN_WIDTH)) = color;
}

static void	init_line(t_tline *l, int ll[4])
{
	l->x = ll[0];
	l->y = ll[1];
	l->dx = ll[2] - ll[0];
	l->dy = ll[3] - ll[1];
	l->xinc = (l->dx > 0) ? 1 : -1;
	l->yinc = (l->dy > 0) ? 1 : -1;
	l->dx = (l->dx < 0) ? -l->dx : l->dx;
	l->dy = (l->dy < 0) ? -l->dy : l->dy;
}

int		point_in_limit(int a, int b, int limit)
{
	if (a < 0 && b < 0)
		return (0);
	if (a > limit && b > limit)
		return (0);
	return (1);
}

void        put_line(char *img, int line[4], int color)
{
    t_tline		l;
	int			i;

	init_line(&l, line);
	//todo ici il faut trouver un moyens efficasse de ne pas afficher les ligne hors de la carte foret de if ?
	if (!point_in_limit(line[1], line[3], WIN_HEIGHT) || !point_in_limit(line[0], line[2], WIN_WIDTH))
		return ;
	i = 0;
    put_pix(img, l.x, l.y, color);
	if (l.dx > l.dy)
	{
		l.cumul = l.dx / 2;
		while (++i <= l.dx)
		{
			l.x += l.xinc;
			l.cumul += l.dy;
			if (l.cumul >= l.dx)
			{
				l.cumul -= l.dx;
				l.y += l.yinc;
            }
            put_pix(img, l.x, l.y, color);
		}
	}
	else
	{
		l.cumul = l.dy / 2;
		while (++i <= l.dy)
		{
			l.y += l.yinc;
			l.cumul += l.dx;
			if (l.cumul >= l.dy)
			{
				l.cumul -= l.dy;
				l.x += l.xinc;
            }
			put_pix(img, l.x, l.y, color);
		}
	}
}
