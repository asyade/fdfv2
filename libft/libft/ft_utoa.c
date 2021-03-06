/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:42:26 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 02:42:29 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countchar(unsigned int nbr, size_t base)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	else
	{
		while (nbr != 0)
		{
			nbr /= base;
			i++;
		}
		return (i);
	}
}

char	*ft_utoa(unsigned int nbr, char const *base_chr)
{
	char			*buf;
	int				i;
	size_t			base;

	base = ft_strlen(base_chr);
	if ((buf = ft_strnew(ft_countchar(nbr, base))) == NULL)
		return (NULL);
	i = 0;
	if (nbr == 0)
		buf[i++] = '0';
	while (nbr > 0)
	{
		buf[i++] = base_chr[nbr % base];
		nbr /= base;
	}
	buf[i] = '\0';
	ft_strrev(buf);
	return (buf);
}
