/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:52:15 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 18:21:25 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *tf, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (tf[j] == str[i + j] && (j + i) < n && tf[j])
			++j;
		if (!(tf[j]))
			return ((char*)(str + i));
		++i;
	}
	return (NULL);
}
