/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:42:23 by mimatsub          #+#    #+#             */
/*   Updated: 2022/07/30 16:48:10 by mimatsub         ###   ########.fr       */
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
			count += ft_putchar_fd(input[i]);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
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
    int num1 = ft_printf("m_c char  > %c            %c  <   ", 'a', 'b');
    printf("%d \n", num1);
    int num2 = printf("o_c char  > %c            %c  <   ", 'a', 'b');
    printf("%d \n", num2);

    printf("\n");
    static char str = '\0';
    num1 = ft_printf("m_c char  > %c            %c  <   ", str, 'b');
    printf("%d \n", num1);
    num2 = printf("o_c char  > %c            %c  <   ", str, 'b');
    printf("%d \n", num2);

    printf("\n");
    num1 = ft_printf("m_s string    > %s            %s  <   ", "hey", "siri");
    printf("%d \n", num1);
    num2 = printf("o_s string    > %s            %s  <   ", "hey", "siri");
    printf("%d \n", num2);

    printf("\n");
    num1 = ft_printf("m_s string    > %s            %s  <   ", "", "\0");
    printf("%d \n", num1);
    num2 = printf("o_s string    > %s            %s  <   ", "", "\0");
    printf("%d \n", num2);

    printf("\n");
    int num = 1;
    int *p_num1 = &num;
    num1 = ft_printf("m_p poiner    > %p %p <   ", "hey", p_num1);
    printf("%d \n", num1);
    num2 = printf("o_p poiner    > %p %p <   ", "hey", p_num1);
    printf("%d \n", num2);

    printf("\n");
    num1 = ft_printf("m_d digit     > %d            %d  <   ", -123, 0);
    printf("%d \n", num1);
    num2 = printf("o_d digit     > %d            %d  <   ", -123, 0);
    printf("%d \n", num2);

    printf("\n");
    num1 = ft_printf("m_i int   > %i            %i  <   ", -123, 42);
    printf("%d \n", num1);
    num2 = printf("o_i int   > %i            %i  <   ", -123, 42);
    printf("%d \n", num2);

    printf("\n");
    num1 = ft_printf("m_u uint  > %u            %u  <   ", 1, 4321);
    printf("%d \n", num1);
    num2 = printf("o_u uint  > %u            %u  <   ", 1, 4321);
    printf("%d \n", num2);

    printf("\n");
    num1 = ft_printf("m_x hex   > %x        %x  <   ", -1, 4321);
    printf("%d \n", num1);
    num2 = printf("o_x hex   > %x        %x  <   ", -1, 4321);
    printf("%d \n", num2);

    printf("\n");
    num1 = ft_printf("m_x hex   > %X        %X  <   ", -1, 42);
    printf("%d \n", num1);
    num2 = printf("o_x hex   > %X        %X  <   ", -1, 42);
    printf("%d \n", num2);

    printf("\n");
    num1 = ft_printf("m_%% %%       > %c            %s  <   ", 'a', "abc");
    printf("%d \n", num1);
    num2 = printf("o_%% %%       > %c            %s  <   ", 'a', "abc");
    printf("%d \n", num2);

    return (0);
}

#include <stdio.h>
int main(void)
{
	ft_printf("hoge%x\n", -1);
	printf("hoge%x\n", -1);
}
*/