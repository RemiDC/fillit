/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:24:48 by reda-con          #+#    #+#             */
/*   Updated: 2018/11/23 18:24:58 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ct_wrds(char const *s, char c)
{
	int		i;
	size_t	wrds;

	i = 0;
	wrds = 0;
	while (s[i] == c)
		++i;
	if (s[i])
		++wrds;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				++i;
			if (s[i])
				++wrds;
		}
		if (s[i])
			++i;
	}
	return (wrds);
}

static size_t	ct_char(char const *s, char c, int i)
{
	size_t	chr;

	chr = 0;
	while (s[i] && s[i] != c)
	{
		++i;
		++chr;
	}
	return (chr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	size_t	j;
	int		k;

	if (!s)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * (ct_wrds(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ct_wrds(s, c))
	{
		k = 0;
		while (s[i] == c)
			++i;
		if (!(ret[j] = (char*)malloc(sizeof(char) * (ct_char(s, c, i) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
			ret[j][k++] = s[i++];
		ret[j++][k] = '\0';
	}
	ret[j] = 0;
	return (ret);
}
