/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:16:45 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 17:30:32 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	t_list	*tf;

	if (*alst == NULL || del == NULL)
		return ;
	tf = NULL;
	tf = *alst;
	del(tf->content, tf->content_size);
	free(tf);
	*alst = NULL;
}
