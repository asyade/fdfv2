#include "fdf.h"

int    key_scale(int key, t_render *r)
{
    if (key == 4)
        apply_scale(r->map, SCALE_VEL);
    else if (key == 5)
        apply_scale(r->map, SCALE_VEL_OUT);
    else
        return (0);
    return (1);
}

int    key_move(int key, t_render *r)
{
    (void)r;
    int vel;

    vel = WIN_WIDTH / ((r->map->width + r->map->height) / 4);
    if (key == 65361)//left
        r->origin.x += vel;
    else if (key == 65363)//right
        r->origin.x -= vel;
    else if (key == 65362)//up
        r->origin.y += vel;
    else if (key == 65364)//down
        r->origin.y -= vel;
    else
        return (key_scale(key, r));
    return (1);
}

int     key_event(int key, void *p)
{
    t_render    *render;

    (void)p;
    render = render_get();
    if (key == 65307)
        render_stop(&render);
    else if (key == 65431)//up
        render->rot.rot.x += ROT_VEL;
    else if (key == 65433)//down
        render->rot.rot.x -= ROT_VEL;
    else if (key == 65430)
        render->rot.rot.y -= ROT_VEL;
    else if (key == 65432)
        render->rot.rot.y += ROT_VEL;
    else if (key == 65429)
        render->rot.rot.z += ROT_VEL;
    else if (key == 65434)
        render->rot.rot.z -= ROT_VEL;
    else if (!key_move(key, render))
        return (0);
    render->flags = 0xFFFFFFFF;
    render_apply(render);
    return (1);
}

int     mouse_event(int x, int y, int btn, void *p)
{
    (void)x;
    (void)y;
    (void)btn;
    (void)p;
    return (1);
}