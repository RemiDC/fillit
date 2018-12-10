/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:49:30 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/11/23 17:44:38 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrealloc(char *s, size_t size)
{
	size_t		i;
	char		*ret;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s[i] && i < size)
	{
		ret[i] = s[i];
		++i;
	}
	while (i < size)
	{
		ret[i] = '\0';
		++i;
	}
	ret[i] = '\0';
	free(s);
	s = NULL;
	return (ret);
}
