#include "fdf.h"

int    key_scale(int key, t_render *r)
{
    if (key == 69)
        apply_scale(r->map, SCALE_VEL);
    else if (key == 78)
        apply_scale(r->map, SCALE_VEL_OUT);
    else if (key == 115)
        apply_height(r->map, HEIGHT_VEL);
    else if (key == 119)
        apply_height(r->map, HEIGHT_VEL);
    else
        return (0);
    return (1);
}

int    key_move(int key, t_render *r)
{
    int vel;

    vel = WIN_WIDTH / ((r->map->width + r->map->height) / 4);
    if (key == 123)//left
        r->origin.x += vel;
    else if (key == 124)//right
        r->origin.x -= vel;
    else if (key == 126)//up
        r->origin.y += vel;
    else if (key == 125)//down
        r->origin.y -= vel;
    else if (key == 53)
        r->fill = (r->fill) ? 0 : 1;
    else
        return (key_scale(key, r));
    return (1);
}

int     key_event(int key, void *p)
{
    t_render    *render;

    printf("key %d\n", key);
    (void)p;
    render = render_get();
    if (key == 53)
        render_stop(&render);
    else if (key == 91)//up
        render->rot.rot.x += ROT_VEL;
    else if (key == 84)//down
        render->rot.rot.x -= ROT_VEL;
    else if (key == 86)
        render->rot.rot.y -= ROT_VEL;
    else if (key == 88)
        render->rot.rot.y += ROT_VEL;
    else if (key == 89)
        render->rot.rot.z += ROT_VEL;
    else if (key == 92)
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