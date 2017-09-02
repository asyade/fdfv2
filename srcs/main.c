#include "fdf.h"
#include "fcntl.h"

int		main(int ac, char **av)
{
	int			fd;
	t_map		*map;
	t_render	*render;

	if (ac != 2)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) <= 0)
		return (1);
	map = fdf_parse(fd);
	if (map->error)
	{
		ft_putendl("Map invalide");
		exit(1);
	}
	render = render_init(map);
	render_loop(render);
	render_stop(&render);
}