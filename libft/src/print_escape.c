/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_escape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:34:53 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 02:35:52 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_escape(t_fmt *arg)
{
	(void)arg;
	if (arg->flags & PFF_HASWIDTH && !(arg->flags & PFF_PADRIGHT))
		print_padd(1, arg->width, arg->flags & PFF_NOPAD ? PDNO : PDSP);
	pf_putchar(FMTCHR);
	pf_gprintpost(arg, 1, PDSP);
	return (arg->flags & PFF_HASWIDTH ? ft_max(arg->width, 1) : 1);
}
