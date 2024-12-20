/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:42:04 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:08:47 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, s);
	i = -1;
	count = 0;
	if (!s[0])
		return (-1);
	while (++i < (int)ft_strlen(s))
	{
		printf_init(s, ap, &count, &i);
		if (s[i] != '\0')
		{
			ft_putchar_fd(s[i], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
