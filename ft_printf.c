/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:42:23 by mimatsub          #+#    #+#             */
/*   Updated: 2022/07/30 03:22:17 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_treat_str(char *s)
{
    if (!s)
        s = "(null)";
    ft_putstr_fd(s, 1);
    return (ft_strlen(s));
}

int ft_treat_char(int c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

int ft_treat_something(char c, va_list ap)
{
    size_t count;

    count = 0;
    if (c == 'c')
        count = ft_treat_char(va_arg(ap, int));
    else if (c == 's')
        count = ft_treat_str(va_arg(ap, char *));
    else if (c == 'p')
        count = ft_treat_point((unsigned long long)va_arg(ap, void *));
    else if (c == 'x' || c == 'X' || c == 'u')
        count = ft_treat_base(va_arg(ap, unsigned int), c);
    else if (c == 'i' || c == 'd')
        count = ft_treat_int(va_arg(ap, int));
    else if (c == '%')
        count = ft_treat_char('%');
    return (count);
}

int ft_count_output(const char *input, va_list ap)
{
    size_t i;
    size_t count;

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
            ft_putchar_fd(input[i], 1);
            count++;
        }
        i++;
    }
    return (count);
}

int ft_printf(const char* input, ...)
{
    va_list ap;
    size_t count; 

    count = 0;
    va_start(ap, input);
    count = ft_count_output(input, ap);
    va_end(ap);
    return (count);
}


#include <stdio.h>
int main(void)
{
    ft_printf("hoge%x\n", -1);
    printf("hoge%x\n", -1);
}
