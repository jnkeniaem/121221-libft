/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:22:05 by jeekim            #+#    #+#             */
/*   Updated: 2021/12/12 21:46:50 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_spl_cnt(const char *s, char c)
{
	unsigned int	s_idx;
	unsigned int	spl_cnt;

	s_idx = 0;
	spl_cnt = 0;
	while (s[s_idx])
	{
		if (s[s_idx] == c)
			s_idx++;
		else
		{
			while (s[s_idx] != c && s[s_idx])
				s_idx++;
			spl_cnt++;
		}
	}
	return (spl_cnt);
}

static char	*ft_strndup(const char *s, unsigned int spl_len)
{
	unsigned int	s_idx;
	char			*dup;

	if (!s || spl_len == 0)
		return (NULL);
	dup = (char *)malloc(spl_len + 1);
	if (dup == NULL)
		return (NULL);
	s_idx = 0;
	while (s_idx < spl_len)
	{
		dup[s_idx] = s[s_idx];
		s_idx++;
	}
	dup[s_idx] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char			**new;
	unsigned int	new_idx;
	unsigned int	s_idx;
	unsigned int	spl_len;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (ft_spl_cnt(s, c) + 1));
	if (new == NULL)
		return (NULL);
	new_idx = 0;
	s_idx = 0;
	while (s[s_idx] && s_idx < ft_strlen(s))
	{
		spl_len = 0;
		if (s[s_idx] != c && s[s_idx])
		{
			while (s[s_idx + spl_len] != c && s[s_idx + spl_len])
				spl_len++;
			new[new_idx++] = ft_strndup(s + s_idx, spl_len);
		}
		s_idx += spl_len + 1;
	}
	new[new_idx] = NULL;
	return (new);
}
