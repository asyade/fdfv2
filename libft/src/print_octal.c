/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:26:12 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 03:32:24 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_octal(va_list *args, t_fmt *arg)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, uintmax_t);
	if (arg->flags & PFF_FORCPREFIX && nbr == 0 &&
arg->flags & PFF_HASPRES && arg->precs == 0)
	{
		pf_gprintpre(arg, 1, 0);
		pf_gprintpost(arg, 1, PDNO);
		return (arg->flags & PFF_HASWIDTH ? ft_max(arg->width, 1) : 1);
	}
	if (arg->flags & PFF_FORCPREFIX && nbr != 0)
	{
		arg->flags |= PFF_HASPRES;
		arg->precs = ft_max(arg->precs,
		ft_nbrlen(nbr, BASE_OCTAL) + 1);
	}
	return (print_uint(nbr, arg, BASE_OCTAL, NULL));
}

ssize_t	print_binary(va_list *args, t_fmt *arg)
{
	uintmax_t	nbr;

	nbr = pf_getsint(args, arg);
	return (print_uint(nbr, arg, BASE_BIN, PREFIX_BIN));
}
