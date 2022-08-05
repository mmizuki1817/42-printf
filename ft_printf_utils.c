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

size_t	ft_put_base(unsigned long long num, char c, int base)
{
	size_t count;
	if (num < (unsigned long long)base)
	{
		if (num <= 9)
			count += ft_putchar_fd(num + '0');
		else if (num > 9 && c == 'x')
			count += ft_putchar_fd('a' + num - 10);
		else if (num > 9 && c == 'X')
			count += ft_putchar_fd('A' + num - 10);
	}
	else
	{
		count = ft_put_base(num / base, c, base);
		count = ft_put_base(num % base, c, base);
	}
	return (count);
}

size_t	ft_treat_int(int i)
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
	count = ft_put_base(li, 'i', base);
	if (li == 0)
		return (1);
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
	count = ft_put_base((unsigned long long)num, c, base);
	if (num == 0)
		return (1);
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
