/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:46:45 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 18:25:45 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ct_i(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ',')
		++i;
	return (i);
}

static size_t	ct_j(char const *s)
{
	size_t	j;

	j = 0;
	while (s[j])
		++j;
	--j;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == ',')
		--j;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	i;
	size_t	j;
	int		k;

	if (!s)
		return (NULL);
	i = ct_i(s);
	j = ct_j(s);
	if (i < j)
	{
		if (!(ret = (char*)malloc(sizeof(char) * (j - i + 2))))
			return (NULL);
	}
	else
	{
		if (!(ret = (char*)malloc(sizeof(char))))
			return (NULL);
	}
	k = 0;
	while (i <= j)
		ret[k++] = s[i++];
	ret[k] = '\0';
	return (ret);
}
