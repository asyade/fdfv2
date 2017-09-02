/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfn1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:30:51 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 02:31:27 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putstr(const char *str)
{
	if (!str || !*str)
		return ;
	pf_write(str, ft_strlen(str));
}

void	pf_putnstr(const char *str, size_t n)
{
	if (!str || !*str)
		return ;
	pf_write(str, n);
}

void	pf_putchar(char c)
{
	pf_write(&c, 1);
}
