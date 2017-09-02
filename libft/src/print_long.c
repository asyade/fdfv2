/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:25:00 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 02:26:03 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t			print_long(char **format, va_list *args, t_fmt *arg)
{
	(void)format;
	arg->flags |= PFF_L;
	return (print_int(args, arg));
}

ssize_t			print_ulong(char **format, va_list *args, t_fmt *arg)
{
	uintmax_t		nbr;
	char			*pr;

	(void)format;
	arg->flags |= PFF_L;
	pr = STREMPTY;
	arg->flags = (arg->flags & PFF_HASPRES) ?
arg->flags & ~PFF_NOPAD : arg->flags;
	nbr = get_sval(args, arg);
	if (!(arg->flags & (PFF_SHOWSING | PFF_BLANKSIGN)))
		return (print_uint(nbr, arg, BASE_NUM, NULL));
	else if (arg->flags & PFF_SHOWSING)
		pr = SMORE;
	else if (arg->flags & PFF_BLANKSIGN)
		pr = SSP;
	return (print_presint(nbr, BASE_NUM, arg, pr));
}
