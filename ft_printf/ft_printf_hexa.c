/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:15:24 by wewang            #+#    #+#             */
/*   Updated: 2022/10/26 11:16:20 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa_l(int nb, int *c_count)
{
	unsigned int	number;

	number = (unsigned int)nb;
	if (number >= 16)
	{
		ft_print_hexa_l(number / 16, c_count);
		number %= 16;
	}
	ft_print_character("0123456789abcdef"[number], c_count);
}

void	ft_print_hexa_u(int nb, int *c_count)
{
	unsigned int	number;

	number = (unsigned int)nb;
	if (number >= 16)
	{
		ft_print_hexa_u(number / 16, c_count);
		number %= 16;
	}
	ft_print_character("0123456789ABCDEF"[number], c_count);
}
