/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:35:59 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 02:39:31 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_hex(char **fmt, va_list *args, t_fmt *arg)
{
	if (**fmt != 'X')
		return (print_uint(pf_getsint(args, arg), arg, BASE_MIN_HEX, "0x"));
	return (print_uint(pf_getsint(args, arg), arg, BASE_MAJ_HEX, "0X"));
}

ssize_t	print_ptr(va_list *args, t_fmt *arg)
{
	uintmax_t	nb;

	arg->flags |= PFF_Z;
	(arg->flags |= PFF_HASPRES) ? (arg->flags &= ~PFF_NOPAD) : 0;
	nb = pf_getsint(args, arg);
	if (nb == 0)
	{
		pf_putstr("0x0");
		return (3);
	}
	return (print_presint(nb,
				BASE_MIN_HEX, arg, PREFIX_HEX));
}
