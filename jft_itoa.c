/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:06:02 by jeekim            #+#    #+#             */
/*   Updated: 2021/12/10 14:33:06 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

static int	ft_nbrlen(int nbr)
{
	int	len;

	if (nbr < 0)
		len = 1;
	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		flag;
	int		len;

	if (n < 0)
		flag = -1;
	flag = 1;
	p = (char *)malloc(ft_nbrlen(n) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	len = ft_nbrlen(n);
	p[len] = 0;
	len--;
	while (len--)
	{
		p[ft_nbrlen(n)] = ft_abs(n) % 10;
		n = n / 10;
	}
	if (flag == 1)
		p[ft_nbrlen(n)] = '-';
	return (p);
}
