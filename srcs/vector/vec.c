#include "vector.h"

t_vec2  *vec2_new(t_dec x, t_dec y)
{
    t_vec2  *ret;

    ret = ft_salloc(sizeof(t_vec2));
    ret->x = x;
    ret->y = y;
    return (ret);
}

t_vec3		*vec3_set(t_vec3 *ret, t_dec x, t_dec y, t_dec z)
{
    ret->x = x;
    ret->y = y;
    ret->z = z;
    return (ret);
}

t_vec3  *vec3_new(t_dec x, t_dec y, t_dec z)
{
    t_vec3  *ret;

    ret = ft_salloc(sizeof(t_vec3));
    ret->x = x;
    ret->y = y;
    ret->z = z;
    return (ret);
}

t_vec4  *vec4_new(t_dec x, t_dec y, t_dec z, t_dec n)
{
    t_vec4  *ret;

    ret = ft_salloc(sizeof(t_vec4));
    ret->x = x;
    ret->y = y;
    ret->z = z;
    ret->n = n;
    return (ret);
}

t_vec4  *vec4_set(t_vec4 *ret, t_dec x, t_dec y, t_dec z, t_dec n)
{
    ret->x = x;
    ret->y = y;
    ret->z = z;
    ret->n = n;
    return (ret);
}
