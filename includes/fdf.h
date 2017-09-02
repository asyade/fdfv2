#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "structs.h"
# include "vector.h"

# define WIN_WIDTH  1900
# define WIN_HEIGHT 1320

# define F_UPROT    0x0001
# define F_UPORIGIN 0x0002
# define F_REFRESH  0x0004
# define F_OLDREADY 0x0010

# define HEIGHT_VEL 1.5
# define SCALE_VEL  1.5
# define SCALE_VEL_OUT  0.5
# define MOVE_VEL   10
# define ROT_VEL    0.1

# define SLIMIT   30

/*
** return 0 **str != blank
*/

int    fdf_skblank(char **str);

/*
** -+0123456789
*/

int    fdf_isnumbegin(char c);
int    fdf_sknum(char **str);

t_map   *fdf_parse(int fd);

/*
** SDL2 render engine
*/

void		get_limits(t_render *r);
t_render	*render_get();
void		scale_def(t_map *map);
int			render_apply(t_render *render);
int         key_event(int key, void *p);
int         mouse_event(int btn, int x, int y, void *p);
void        put_pix(char *img, int x, int y, int color);
void        put_line(char *img, int line[4], int color);
void        dump_lines(t_render *render, int y, int to);
void        apply_matrice(t_render *render, int y, int to);
void        apply_height(t_map *map, double del);
void        apply_scale(t_map *map, double del);
t_render    *render_init(t_map *map);
void		render_stop(t_render **render);
void		render_loop(t_render *render);

#endif