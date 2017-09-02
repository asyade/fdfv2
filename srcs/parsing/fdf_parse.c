#include "fdf.h"

static int  get_width(char *line)
{
	int		width;
	char	*str;

	width = 0;
	str = line;
	fdf_skblank(&str);
	while (*str && *str != '\n')
	{
		if (!fdf_sknum(&str))
			return (-1);
		width++;
		fdf_skblank(&str);
	}
	return (width);
}

static void	fill_line(char *line, t_vec3 *fill, int y)
{
	char	*str;
	int		x;

	str = line;
	fdf_skblank(&str);
	x = 0;
	while (*str)
	{
		fill->x = (double)x++;
		fill->y = (double)y;
		fill->z = (double)ft_atoiinc(&str);
		fill++;
		fdf_skblank(&str);
	}
}

t_map   	*fdf_parse(int fd)
{
	t_map	*map;
	char	*line;
	int		lsize;
	int		y;
	int		size;
	t_vec3	**tmp;	

	size = 4096;
	map = ft_memalloc(sizeof(t_map));
	line = NULL;
	lsize = 0;
	y = 0;
	map->data = ft_memalloc(sizeof(t_vec3 **) * size);
	map->done = ft_memalloc(sizeof(t_point **) * size);
	map->old = ft_memalloc(sizeof(t_point **) * size);
	while (get_next_line(fd, &line))
	{
		if (y > size)
		{
			tmp = ft_memalloc(sizeof(t_vec3 **) * (size * 2));
			ft_memcpy(tmp, map->data, size);
			free(map->data);
			map->data = tmp;
			size *= 2;
		}
		lsize = (!lsize) ? get_width(line) : lsize;
		if (get_width(line) != lsize)
		{
			map->error = 1;
			break ;
		}
		map->data[y] = ft_memalloc(sizeof(t_vec3) * lsize);
		map->done[y] = ft_memalloc(sizeof(t_point) * lsize);
		map->old[y] = ft_memalloc(sizeof(t_point) * lsize);
		fill_line(line, map->data[y], y);
		y++;
	}
	map->height = y;
	map->width = lsize;
	return (map);
}