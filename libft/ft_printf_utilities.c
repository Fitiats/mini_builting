/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmory < tmory@student.42antananarivo.mg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:44:16 by tmory             #+#    #+#             */
/*   Updated: 2024/08/12 15:08:38 by tmory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_u(const char *s, va_list ap, int *i, int	*count)
{
	unsigned int	i3;

	i3 = 0;
	if (s[*i] == 'u')
	{
		i3 = (va_arg(ap, unsigned int));
		ft_putnbr_ui(i3, 1, count);
		(*i)++;
	}
}

static void	ft_printf_x(const char *s, va_list ap, int *i, int	*count)
{
	unsigned long	p;

	if (s[*i] == 'x' || s[*i] == 'X')
	{
		if (s[*i] == 'x')
		{
			p = va_arg(ap, unsigned int);
			ft_putnbr_base(p, "0123456789abcdef", count);
			(*i)++;
		}
		else if (s[*i] == 'X')
		{
			p = va_arg(ap, unsigned int);
			ft_putnbr_base(p, "0123456789ABCDEF", count);
			(*i)++;
		}
	}
}

static void	ft_printf_s(const char *s, va_list ap, int *count, int *i)
{
	int				i2;
	char			*str;

	if (s[*i] == 's')
	{
		i2 = 0;
		str = va_arg(ap, char *);
		if (str == NULL)
		{
			ft_putstr_fd("(null)", 1);
			(*i)++;
			(*count) += 6;
			return ;
		}
		while (str[i2] != '\0')
		{
			ft_putchar_fd(str[i2], 1);
			i2++;
			(*count)++;
		}
		(*i)++;
	}
}

static void	ft_printf_p(const char *s, va_list ap, int *count, int *i)
{
	unsigned long	p;

	if (s[*i] == 'p')
	{
		p = va_arg(ap, unsigned long);
		if (p == 0)
		{
			ft_putstr_fd("(nil)", 1);
			(*i)++;
			(*count) += 5;
			return ;
		}
		write(1, "0x", 2);
		ft_putnbr_base(p, "0123456789abcdef", count);
		(*count) += 2;
		(*i)++;
	}
}

void	printf_init(const char *s, va_list ap, int *count, int *i)
{
	int	i2;

	i2 = 0;
	while (s[*i] == '%' && s[(*i)++])
	{
		if (s[*i] == '%')
			ft_putchar_printf('%', 1, i, count);
		else if (s[*i] == 'c')
			ft_putchar_printf(va_arg(ap, int), 1, i, count);
		else if (s[*i] == 's')
			ft_printf_s(s, ap, count, i);
		else if (s[*i] == 'p')
			ft_printf_p(s, ap, count, i);
		else if (s[*i] == 'd' || s[*i] == 'i')
		{
			i2 = (va_arg(ap, int));
			ft_putnbr(i2, 1, count);
			(*i)++;
		}
		else if (s[*i] == 'u')
			ft_printf_u(s, ap, i, count);
		else if (s[*i] == 'x' || s[*i] == 'X')
			ft_printf_x(s, ap, i, count);
	}
}
