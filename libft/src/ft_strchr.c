/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:01:02 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 17:37:02 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!c)
	{
		while (s[i])
			++i;
		return ((char*)(s + i));
	}
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)(s + i));
		++i;
	}
	return (NULL);
}
