/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:16:39 by wewang            #+#    #+#             */
/*   Updated: 2022/10/26 11:19:06 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_address_helper(unsigned long addr, int *c_count)
{
	if (addr >= 16)
	{
		ft_print_address_helper(addr / 16, c_count);
		addr %= 16;
	}
	ft_print_character("0123456789abcdef"[addr], c_count);
}

void	ft_print_address(unsigned long addr, int *c_count)
{
	if (addr == 0)
		ft_print_string("(nil)", c_count);
	else
	{
		ft_print_string("0x", c_count);
		ft_print_address_helper(addr, c_count);
	}
}
