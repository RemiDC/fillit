/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:10:42 by reda-con          #+#    #+#             */
/*   Updated: 2018/12/10 11:40:08 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			*(unsigned char*)(dest - i) = *(unsigned char*)(src - i);
			--i;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
