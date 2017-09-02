#include "libft.h"
#define BW_SIZE	4096

void	ft_bflush(char *str, int len)
{
	static char		buffer[BW_SIZE] = {0};
	static size_t	ptr = 0;

	if (!str)
	{
		ft_putstr(buffer);
		buffer[0] = '\0';
		ptr = 0;
		return ;
	}
	if (len + ptr + 1 > BW_SIZE)
	{
		ft_bflush(NULL, 0);
		return (ft_bflush(str, len));
	}
	ft_memcpy(buffer + ptr, str, len);
	*(buffer + ptr + len + 1) = '\0';
}

void	ft_bwrite(size_t len, char *str)
{
	ft_bflush(str, len);
}