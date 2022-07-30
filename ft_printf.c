/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:42:23 by mimatsub          #+#    #+#             */
/*   Updated: 2022/07/30 16:18:09 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_treat_str(char *s)
{
	size_t	len;

	if (!s)
	{
		s = "(null)";
		return (6);
	}	
	ft_putstr_fd(s, 1);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_putchar_fd(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_treat_something(char c, va_list ap)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_fd(va_arg(ap, int));
	else if (c == 's')
		count = ft_treat_str(va_arg(ap, char *));
	else if (c == 'p')
		count = ft_treat_point((unsigned long long)va_arg(ap, void *));
	else if (c == 'x' || c == 'X' || c == 'u')
		count = ft_treat_base(va_arg(ap, unsigned int), c);
	else if (c == 'i' || c == 'd')
		count = ft_treat_int(va_arg(ap, int));
	else if (c == '%')
		count = ft_putchar_fd('%');
	return (count);
}

static int	ft_count_output(const char *input, va_list ap)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			count += ft_treat_something(input[i], ap);
		}
		else
		{
			count = ft_putchar_fd(input[i]);
		}
		i++;
	}
	return (count);
}

static int	ft_printf(const char *input, ...)
{
	va_list	ap;
	size_t	count;

	count = 0;
	va_start(ap, input);
	count = ft_count_output(input, ap);
	va_end(ap);
	return (count);
}

/*
#include <stdio.h>
int main(void)
{
	ft_printf("hoge%x\n", -1);
	printf("hoge%x\n", -1);
}
*/