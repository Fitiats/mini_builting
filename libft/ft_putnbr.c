/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:57:32 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:10:07 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int fd, int *count)
{
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		(*count) += 11;
	}
	if (n < 0 && n != INT_MIN)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		(*count)++;
	}
	if (n < 10 && n >= 0 && n != INT_MIN)
	{
		ft_putchar_fd(n + 48, fd);
		(*count)++;
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, fd, count);
		ft_putnbr(n % 10, fd, count);
	}
}
