/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:39:24 by aeberius          #+#    #+#             */
/*   Updated: 2025/07/01 15:40:14 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

int print_d (int nbr)
{
	int count = 0;
	char number;
	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return(11);
	}
	if (nbr < 0)
	{
		count += write (1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		count += print_d(nbr/10);
		number = nbr%10 + '0';
		count += write(1, &number, 1);
	}
	else
	{
		number = nbr + '0';
		count += write(1, &number, 1);
	}
	return (count);
}
int print_s (char* str)
{
	int i = 0;
	int count = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return(6);
	}
	while (str[i] != '\0')
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}
int	print_x (unsigned int hex)
{
	int count = 0;
	char* base = "0123456789abcdef";
	if(hex / 16 > 0)
		count += print_x(hex/16);
	count += write (1, &base[hex%16], 1);
	return (count);
}
int ft_printf (const char *format, ...)
{
	int count = 0;
	int i = 0;
	va_list list;
	va_start (list, format);
	
	while(format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if(format[i] == 'd')
				count += print_d(va_arg(list, int));
			if (format[i] == 's')
				count += print_s(va_arg(list, char*));
			 if (format[i] == 'x')
				count += print_x(va_arg(list, unsigned int));
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}
