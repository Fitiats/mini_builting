/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:33:47 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:09:43 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long nbr, char *base, int *count)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nbr < (unsigned long) base_len)
	{
		ft_putchar_fd(base[nbr], 1);
		(*count)++;
	}
	else
	{
		ft_putnbr_base(nbr / base_len, base, count);
		ft_putchar_fd(base[nbr % base_len], 1);
		(*count)++;
	}
}
