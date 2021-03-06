/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:51:02 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/15 15:03:33 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n)
{
	if (n > -10 && n < 10)
	{
		if (n < 0)
			return (2);
		else
			return (1);
	}
	return (count_len(n / 10) + 1);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*str;

	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len + 1);
	str[0] = (n < 0) ? '-' : str[0];
	str[0] = (n == 0) ? '0' : str[0];
	while (len-- && n != 0)
	{
		str[len] = (n < 0) ? -(n % 10) + '0' : (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
