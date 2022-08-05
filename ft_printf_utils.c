/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 03:11:07 by mimatsub          #+#    #+#             */
/*   Updated: 2022/08/05 16:48:14 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_base(unsigned long long num, char c, int base)
{
	if (num < (unsigned long long)base)
	{
		if (num <= 9)
			ft_putchar_fd(num + '0');
		else if (num > 9 && c == 'x')
			ft_putchar_fd('a' + num - 10);
		else if (num > 9 && c == 'X')
			ft_putchar_fd('A' + num - 10);
	}
	else
	{
		ft_put_base(num / base, c, base);
		ft_put_base(num % base, c, base);
	}
	return ;
}

int	ft_treat_int(int i)
{
	size_t				count;
	int					base;
	unsigned long long	li;

	if (!i)
		i = 0;
	count = 0;
	li = (unsigned long long)i;
	if (i < 0)
	{
		ft_putchar_fd('-');
		count = 1;
		li = li * (-1);
	}
	base = 10;
	ft_put_base(li, 'i', base);
	if (li == 0)
		return (1);
	while (li > 0)
	{
		li = li / base;
		count ++;
	}
	return (count);
}

size_t	ft_treat_base(unsigned int num, char c)
{
	size_t	count;
	int		base;

	if (!num)
		num = 0;
	if (c == 'x' || c == 'X')
		base = 16;
	else
		base = 10;
	ft_put_base((unsigned long long)num, c, base);
	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
		count++;
	}
	return (count);
}

size_t	ft_treat_point(unsigned long long p)
{
	size_t	count;

	count = 0;
	if (!p)
		return (ft_putstr_fd("0x0"));
	count += ft_putstr_fd("0x");
	count += ft_put_base(p, 'x', 16);
	return (count);
}
