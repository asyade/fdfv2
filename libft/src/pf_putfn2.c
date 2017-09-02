/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfn2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:30:51 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 02:31:27 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	inner(uintmax_t nbr, char *base, size_t len)
{
	if (nbr >= len)
	{
		inner(nbr / len, base, len);
		inner(nbr % len, base, len);
	}
	else
		pf_putchar(base[nbr]);
}

void		pf_putwchar(wchar_t chr)
{
	if ((MB_CUR_MAX == 1 && chr > 0x7FF) || (MB_CUR_MAX == 2 && chr > 0xFFFF))
		return ;
	if (MB_CUR_MAX == 3 && chr > 0x10FFFF)
		return ;
	if (chr <= 0x7F)
		pf_putchar(chr);
	else if (chr <= 0x7FF)
	{
		pf_putchar((chr >> 6) + 0xC0);
		pf_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		pf_putchar((chr >> 12) + 0xE0);
		pf_putchar(((chr >> 6) & 0x3F) + 0x80);
		pf_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		pf_putchar((chr >> 18) + 0xF0);
		pf_putchar(((chr >> 12) & 0x3F) + 0x80);
		pf_putchar(((chr >> 6) & 0x3F) + 0x80);
		pf_putchar((chr & 0x3F) + 0x80);
	}
}

void		pf_putwstr(wchar_t *str)
{
	while (*str)
		pf_putwchar(*str++);
}

void		pf_putnwstr(wchar_t *str, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && str[i])
		pf_putwchar(str[i++]);
}

void		pf_putnbrbase(uintmax_t nbr, char *base)
{
	inner(nbr, base, ft_strlen(base));
}
