/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:23:43 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/14 14:56:07 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void		free_old(t_list **lst, char *out)
{
	t_list		*pr;
	t_list		*fptr;

	pr = *lst;
	while (pr)
	{
		fptr = pr;
		pr = pr->next;
		free(fptr->content);
		free(fptr);
	}
	free(out);
	*lst = NULL;
}

static t_list	**buffer_accesor(int w)
{
	static t_list	*buffs = NULL;
	char			*out;
	int				total;
	t_list			*ptr;

	total = 0;
	if (!(w && buffs) || !(ptr = buffs))
		return (&buffs);
	while (ptr)
	{
		total += ft_strlen((char *)ptr->content);
		ptr = ptr->next;
	}
	if (!(out = malloc(sizeof(char) * total + 1)))
		return (NULL);
	out[0] = '\0';
	ptr = buffs;
	while (ptr)
	{
		ft_strcat(out, (char *)ptr->content);
		ptr = ptr->next;
	}
	ft_putstr(out);
	free_old(&buffs, out);
	return (&buffs);
}

void			pf_write(const char *str, size_t len)
{
	t_list	**buffs;

	if (!str || !*str)
		return ;
	buffs = buffer_accesor(0);
	ft_lstaddfront(buffs, ft_lstcreate(ft_strndup(str, len), sizeof(char *)));
}

void			pf_close(void)
{
	buffer_accesor(1);
}
