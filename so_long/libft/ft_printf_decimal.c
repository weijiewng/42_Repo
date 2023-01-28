/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:16:04 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:06:44 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_decimal(int nb, int *c_count)
{
	if (nb == -2147483648)
	{
		ft_print_character('-', c_count);
		ft_print_character('2', c_count);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_print_character('-', c_count);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_print_decimal(nb / 10, c_count);
		nb %= 10;
	}
	ft_print_character(nb + '0', c_count);
}

void	ft_print_unsigned_decimal(unsigned int nb, int *c_count)
{
	if (nb >= 10)
	{
		ft_print_unsigned_decimal(nb / 10, c_count);
		nb %= 10;
	}
	ft_print_character(nb + '0', c_count);
}
