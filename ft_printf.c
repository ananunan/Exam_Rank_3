/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:37:01 by aeberius          #+#    #+#             */
/*   Updated: 2025/03/10 14:37:17 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

void	print_s(char *str, int *count)
{
	int i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		(*count) += write(1, &str[i++], 1);
	return ;
}

void	print_d(int nbr, int base, int *count)
{
	char *str_base = "01233456789";

	if (nbr == INT_MIN)
	{
		(*count) += write(1, "-2", 2);
		nbr = 147483648;
	}
	if (nbr > base)
		print_d(nbr / base, base, count);
	(*count) += write(1, str_base[nbr % base], 1);
	return ;
}

void	print_x(unsigned int nbr, unsigned int base, int *count)
{
	char *str_base = "01233456789abcdef";

	if (nbr > base)
		print_x(nbr / base, base, count);
	(*count) += write(1, str_base[nbr % base], 1);
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	va_start(args, format);
	while(format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'x'))
		{
			i++;
			if (format[i] == 's')
				print_s(va_arg(args, char *), &count);
			else if (format[i] == 'd')
				print_d(va_arg(args, int), 10, &count);
			else if (format[i] == 'x')
				print_x(va_arg(args, unsigned int), 16, &count);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}