/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:44:02 by wewang            #+#    #+#             */
/*   Updated: 2022/10/26 15:58:45 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_command(char command, va_list ap, int *c_count)
{
	if (command == 'c')
		ft_print_character(va_arg(ap, int), c_count);
	else if (command == 's')
		ft_print_string(va_arg(ap, char *), c_count);
	else if (command == 'p')
		ft_print_address(va_arg(ap, unsigned long), c_count);
	else if (command == 'd' || command == 'i')
		ft_print_decimal(va_arg(ap, int), c_count);
	else if (command == 'u')
		ft_print_unsigned_decimal(va_arg(ap, unsigned int), c_count);
	else if (command == 'x')
		ft_print_hexa_l(va_arg(ap, int), c_count);
	else if (command == 'X')
		ft_print_hexa_u(va_arg(ap, int), c_count);
	else if (command == '%')
		ft_print_character(37, c_count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		res;

	va_start(ap, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_check_command(str[i], ap, &res);
		}
		else
			ft_print_character(str[i], &res);
		i++;
	}
	va_end(ap);
	return (res);
}

// #include <stdio.h>
// #include <limits.h>
// int main()
// {
// 	char *x = NULL;
// 	// int res = ft_printf("%s\n", x);
// 	// ft_printf("%d\n", res);
// 	int res = printf("%s\n", x);
// 	printf("%d\n", res);
// }
