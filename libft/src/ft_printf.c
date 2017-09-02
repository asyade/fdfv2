/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:31:56 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 07:00:07 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_fmt(t_fmt *fmt)
{
	fmt->width = 0;
	fmt->precs = 0;
	fmt->flags = 0;
}

ssize_t			exec_fmt(char **fmt, va_list *v, t_fmt *a)
{
	ssize_t	h;

	h = -1;
	(**fmt == 'p') ? h = print_ptr(v, a) : 0;
	(**fmt == 's') ? h = print_str(v, a) : 0;
	(**fmt == 'c') ? h = print_char(v, a) : 0;
	(**fmt == 'S') ? h = print_wstr(v, a) : 0;
	(**fmt == 'C') ? h = print_wchar(v, a) : 0;
	(**fmt == 'd' || **fmt == 'i') ? h = print_int(v, a) : 0;
	(**fmt == 'o' || **fmt == 'O') ? h = print_octal(v, a) : 0;
	(**fmt == 'D') ? h = print_long(fmt, v, a) : 0;
	(**fmt == 'U') ? h = print_ulong(fmt, v, a) : 0;
	(**fmt == 'u') ? h = print_unsigned(v, a) : 0;
	(**fmt == 'x' || **fmt == 'X') ? h = print_hex(fmt, v, a) : 0;
	(**fmt == 'b') ? h = print_binary(v, a) : 0;
	(**fmt == '%') ? h = print_escape(a) : 0;
	return (h);
}

static ssize_t	pf_fmt(char **str, va_list *args, t_fmt *fmt)
{
	ssize_t		ret;

	if (!(*(++*str)))
		return (-1);
	pf_parse_exp(str, fmt, args);
	if (!**str)
		return (0);
	if (ft_strchr(PF_FMTS, **str))
		ret = exec_fmt(str, args, fmt);
	else
	{
		pf_putchar(**str);
		ret = 2;
	}
	return (++(*str)) ? ret : -1;
}

static int		pf_process(const char *fmt, va_list *args, size_t chrs)
{
	char	*chrptr;
	t_fmt	sarg;
	ssize_t	len;

	while (*fmt && (chrptr = ft_strchr(fmt, FMTCHR)))
	{
		init_fmt(&sarg);
		if (chrptr > fmt)
		{
			pf_putnstr(fmt, chrptr - fmt);
			return (pf_process(chrptr, args, chrs + (chrptr - fmt)));
		}
		else if ((len = pf_fmt((char**)&fmt, args, &sarg)) == -1)
			return (-1);
		chrs += len;
	}
	pf_putstr(fmt);
	return (chrs + ft_strlen(fmt));
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = pf_process(format, &args, 0);
	va_end(args);
	pf_close();
	return (ret);
}
