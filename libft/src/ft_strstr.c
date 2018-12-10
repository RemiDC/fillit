/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:37:14 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 17:44:54 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *tf)
{
	int		i;
	int		j;

	i = 0;
	if (!str[i] && !tf[i])
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		while (tf[j] == str[i + j] && tf[j])
			++j;
		if (!(tf[j]))
			return ((char*)(str + i));
		++i;
	}
	return (NULL);
}
