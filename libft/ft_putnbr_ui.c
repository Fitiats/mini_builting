/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:50:49 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:10:01 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ui(unsigned int n, int fd, int *count)
{
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		(*count)++;
	}
	else if (n >= 10)
	{
		ft_putnbr_ui(n / 10, fd, count);
		ft_putnbr_ui(n % 10, fd, count);
	}
}
