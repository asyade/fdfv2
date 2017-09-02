#include "vector.h"

double  quat_len(t_vec4 *vec)
{
    return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z + vec->n * vec->n));
}

t_vec4  *quat_normalize(t_vec4 *vec)
{
    double  len;

    len = quat_len(vec);
    vec->x /= len;
    vec->y /= len;
    vec->z /= len;
    vec->n /= len;
    return (vec);
}

t_vec4  *quat_conjugate(t_vec4 *vec, t_vec4 *dst)
{
    dst->x = -vec->x;
    dst->y = -vec->y;
    dst->z = -vec->z;
    dst->n = -vec->n;
    return (dst);
}

t_vec4  *quat_mult(t_vec4 *a, t_vec4 *b, t_vec4 *dest)
{
    dest->x = a->n * b->x + a->x * b->n + a->y * b->z - a->z * b->y;
    dest->y = a->n * b->y - a->x * b->z + a->y * b->n + a->z * b->x;
    dest->z = a->n * b->z + a->x * b->y - a->y * b->x + a->z * b->n;
    dest->n = a->n * b->n - a->x * b->x - a->y * b->y - a->z * b->z;    
    return (dest);
}

t_vec4  *quat_from_angle(t_vec4 *q, double angle)
{
    angle = (angle * 0.5) * 3.14159 / 180.0;
    q->x = q->x * sin(angle);
    q->y = q->y * sin(angle);
    q->z = q->z * sin(angle);
    q->n = cos(angle);
    return (q);  
}

t_vec4  *quat_rotat_vertex(t_vec3 *vec, t_vec4 *rot, t_vec4 *dest)
{
    t_vec4  pos;
    t_vec4  rotConj;
    t_vec4  tmp;

    vec4_set(&pos, vec->x, vec->y, vec->z, 0);
    quat_conjugate(rot, &rotConj);
    quat_mult(rot, &pos, &tmp);
    quat_mult(&tmp, &rotConj, dest);
    return (dest);
}