/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:31:40 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 02:31:49 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_padd(int nblen, int width, char padwith)
{
	while (nblen++ < width)
		pf_putchar(padwith);
}

void		pf_gprintpre(t_fmt *arg, int len, char s)
{
	if (!s)
		s = arg->flags & PFF_NOPAD ? PDNO : PDSP;
	if (arg->flags & PFF_HASWIDTH && !(arg->flags & PFF_PADRIGHT))
		print_padd(len, arg->width, s);
}

void		pf_gprintpost(t_fmt *arg, int len, char s)
{
	if (!s)
		s = (arg->flags & PFF_NOPAD) ? PDNO : PDSP;
	if (arg->flags & PFF_HASWIDTH && arg->flags & PFF_PADRIGHT)
		print_padd(len, arg->width, s);
}
