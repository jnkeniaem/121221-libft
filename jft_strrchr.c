/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:42:09 by jeekim            #+#    #+#             */
/*   Updated: 2021/12/03 20:44:13 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len != 0 && s[len] != c)
		len--;
	if (s[len] == c)
		return ((char *)(s + len));
	return (NULL);
}
