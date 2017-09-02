/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiinc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:30:06 by acorbeau          #+#    #+#             */
/*   Updated: 2017/08/13 13:30:51 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoiinc(char **n)
{
	char			*nptr;
	unsigned int	retval;
	int				sign;

	nptr = *n;
	retval = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		sign = (*nptr++ == '+') ? 1 : -1;
	while (ft_isdigit(*nptr))
	{
		retval *= 10;
		retval += *nptr - '0';
		nptr++;
	}
	*n = nptr;
	return ((int)(retval * sign));
}
