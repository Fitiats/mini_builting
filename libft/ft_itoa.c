/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:06:25 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:18:36 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	len;

	len = 0;
	while ((n / 10) != 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char	*assign(char *s, int n, int sign, int len)
{
	int	x;

	if (sign < 0 && sign != INT_MIN)
	{
		n *= -1;
		len++;
	}
	while (len > 0)
	{
		x = n % 10;
		n = (n - x) / 10;
		s[len - 1] = x + '0';
		len--;
	}
	if (sign < 0 && sign != INT_MIN)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;
	int		sign;

	sign = n;
	len = int_len(n);
	if (n == INT_MIN)
	{
		s = ft_strdup("-2147483648");
		return (s);
	}
	if (sign < 0 && sign != INT_MIN)
	{
		s = ft_calloc(len + 2, sizeof(char));
		if (!s)
			return (NULL);
	}
	else
	{
		s = ft_calloc(len + 1, sizeof(char));
		if (!s)
			return (NULL);
	}
	assign(s, n, sign, len);
	return (s);
}
