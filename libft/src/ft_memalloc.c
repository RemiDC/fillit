/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:18:12 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 17:31:00 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*ret;

	i = 0;
	if (!(ret = malloc(size)))
		return (NULL);
	while (i < size)
	{
		*(unsigned char*)(ret + i) = 0;
		++i;
	}
	return (ret);
}
