/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:46:54 by reda-con          #+#    #+#             */
/*   Updated: 2018/12/10 12:00:30 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	i;

	i = ft_strlen(s);
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret = ft_strcpy(ret, s);
	return (ret);
}
