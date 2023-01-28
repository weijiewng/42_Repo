/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:14:14 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:47 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_handle_2_numbers(t_list **stack_a)
{
	if (!ft_check_sorted(*stack_a))
	{
		ra(stack_a);
	}
}

int	ft_handle_3_numbers(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	third = (*stack_a)->next->next->number;
	if (ft_check_sorted(*stack_a))
		return (1);
	if ((second < first && first < third) || (first > second && second > third)
		|| (first < third && third < second))
		sa(*stack_a);
	else if (second < third && third < first)
		ra(stack_a);
	else if (third < first && first < second)
		rra(stack_a);
	return (0);
}

void	ft_handle_4_numbers(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	index;

	min = ft_listget_min(*stack_a);
	index = ft_listget_listindex(*stack_a, min);
	while ((*stack_a)->number != min)
	{
		if (index > 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	while (!ft_handle_3_numbers(stack_a))
		;
	pa(stack_a, stack_b);
}

void	ft_handle_5_numbers(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	index;

	min = ft_listget_min(*stack_a);
	index = ft_listget_listindex(*stack_a, min);
	while ((*stack_a)->number != min)
	{
		if (index > 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	ft_handle_4_numbers(stack_a, stack_b);
	pa(stack_a, stack_b);
}
