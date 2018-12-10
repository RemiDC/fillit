/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:33:17 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 18:23:11 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

char	*ft_strrev(const char *s)
{
	size_t	i;
	char	*ret;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	i = ft_strlen(s);
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	--i;
	while (j < ft_strlen(s))
	{
		ret[j] = s[i];
		--i;
		++j;
	}
	ret[j] = '\0';
	return (ret);
}
