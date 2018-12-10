/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:12:35 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 17:44:37 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		++i;
	while (i > 0)
	{
		if (s[i] == (const char)c)
			return ((char*)(s + i));
		--i;
	}
	if (s[i] == (const char)c)
		return ((char*)s);
	return (NULL);
}
