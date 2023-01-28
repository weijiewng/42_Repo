/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:17:14 by wewang            #+#    #+#             */
/*   Updated: 2022/10/26 11:18:52 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_character(char c, int *c_count)
{
	write(1, &c, 1);
	*c_count = *c_count + 1;
}

void	ft_print_string(char *str, int *c_count)
{
	int	i;

	i = 0;
	if (!str)
		ft_print_string("(null)", c_count);
	else
	{
		while (str[i])
		{
			ft_print_character(str[i], c_count);
			i++;
		}
	}
}
