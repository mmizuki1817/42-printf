/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:44:22 by mimatsub          #+#    #+#             */
/*   Updated: 2022/07/30 02:27:06 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_strlen(char *s);

void ft_put_base(unsigned long long num, char c, int base);

int ft_treat_int(int i);

int ft_treat_base(unsigned int num, char c);

int ft_treat_point(unsigned long long p);

#endif