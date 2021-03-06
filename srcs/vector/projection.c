#include "vector.h"
# include "fdf.h"

void		rot_update(t_rotmatrice *rot)
{
	rot->cx = cos(rot->rot.x);
	rot->cy = cos(rot->rot.y);
	rot->cz = cos(rot->rot.z);
	rot->sx = sin(rot->rot.x);
	rot->sy = sin(rot->rot.y);
	rot->sz = sin(rot->rot.z);
}

void		rot_apply(t_rotmatrice *r, t_vec3 *vec, t_point *dest)
{
	double  z0,y0,x1;
	t_render	*re;

	re = render_get();
	y0  =  ((vec->y - (re->map->scale * re->map->height) / 2)) * r->cx + vec->z*r->sx;
	z0  =  vec->z * r->cx - vec->y*r->sx;
	x1  =  (vec->x - ((re->map->scale * re->map->width) / 2)) *r->cy - z0*r->sy;
	dest->x = (int)(x1*r->cz + y0*r->sz);
	dest->y = (int)(y0 *r->cz - x1*r->sz);
}