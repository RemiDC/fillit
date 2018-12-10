/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:41:50 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 17:30:21 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*to_free;
	t_list	*tmp;

	if (*alst == NULL || del == NULL)
		return ;
	to_free = NULL;
	tmp = NULL;
	to_free = *alst;
	tmp = to_free;
	while (tmp)
	{
		tmp = to_free->next;
		del(to_free->content, to_free->content_size);
		free(to_free);
		to_free = tmp;
	}
	*alst = NULL;
}
