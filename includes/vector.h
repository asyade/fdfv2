#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include "libft.h"

typedef double  t_dec;

typedef struct  s_vec2
{
	t_dec		x;
	t_dec		y;
}               t_vec2;

typedef struct  s_vec3
{
	t_dec		x;
	t_dec		y;
	t_dec		z;
}               t_vec3;

typedef struct  s_vec4
{
	t_dec		x;
	t_dec		y;
	t_dec		z;
	t_dec		n;
}               t_vec4;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_rotmatrice
{
	double		cx;
	double		cy;
	double		cz;
	double		sx;
	double		sy;
	double		sz;
	t_vec3		rot;
}				t_rotmatrice;

/*
**	Basic projection using rotation matrice
**	call rot_update only if rotmatrice.rot changed
**	rot_apply on each point
*/

void			rot_update(t_rotmatrice *rot);
void			rot_apply(t_rotmatrice *r, t_vec3 *vec, t_point *dest);

/*
** Instanciate vector
*/

t_vec2 			*vec2_new(t_dec x, t_dec y);
t_vec3			*vec3_new(t_dec x, t_dec y, t_dec z);
t_vec3			*vec3_set(t_vec3 *ret, t_dec x, t_dec y, t_dec z);
t_vec4			*vec4_new(t_dec x, t_dec y, t_dec z, t_dec n);
t_vec4  		*vec4_set(t_vec4 *ret, t_dec x, t_dec y, t_dec z, t_dec n);
/*
** Baic quaternion calculs
*/

double  		quat_len(t_vec4 *vec);
t_vec4  		*quat_normalize(t_vec4 *vec);
t_vec4  		*quat_conjugate(t_vec4 *vec, t_vec4 *dst);
t_vec4  		*quat_mult(t_vec4 *a, t_vec4 *b, t_vec4 *dest);
t_vec4  		*quat_from_angle(t_vec4 *q, double angle);
t_vec4			*quat_rotat_vertex(t_vec3 *vec, t_vec4 *rot, t_vec4 *dest);
#endif