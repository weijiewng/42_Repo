/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:39:33 by wewang            #+#    #+#             */
/*   Updated: 2022/10/26 14:26:32 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_character(char c, int *c_count);
void	ft_print_string(char *str, int *c_count);
void	ft_print_address_helper(unsigned long addr, int *c_count);
void	ft_print_address(unsigned long addr, int *c_count);
void	ft_print_decimal(int nb, int *c_count);
void	ft_print_unsigned_decimal(unsigned int nb, int *c_count);
void	ft_check_command(char command, va_list ap, int *c_count);
void	ft_print_hexa_l(int nb, int *c_count);
void	ft_print_hexa_u(int nb, int *c_count);
#endif