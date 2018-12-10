/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:35:06 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 17:38:08 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) \
						+ ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		ret[j] = s2[i];
		++i;
		++j;
	}
	ret[j] = '\0';
	return (ret);
}
