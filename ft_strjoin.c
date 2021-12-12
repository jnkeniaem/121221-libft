/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:36:22 by jeekim            #+#    #+#             */
/*   Updated: 2021/12/10 16:01:19 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

static char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		index;
	size_t	j;

	index = 0;
	j = 0;
	while (dest[index] != '\0')
		index++;
	while (j < n && src[j] != '\0')
	{
		dest[index] = src[j];
		index++;
		j++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
	{
		if (!(s1))
			return (ft_strdup(s2));
		return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (newstr == NULL)
		return (NULL);
	ft_strncpy(newstr, s1, s1_len + 1);
	ft_strncat(newstr + (s1_len), s2, s2_len + 1);
	return (newstr);
}
