/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:33:38 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:51 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_check_sorted(t_list *list)
{
	t_list	*current;
	int		tmp;

	if (list == NULL)
		return (1);
	current = list;
	tmp = current->number;
	while (current->next != NULL)
	{
		current = current->next;
		if (tmp < current->number)
			tmp = current->number;
		else
			return (0);
	}
	return (1);
}

void	ft_handle_special_simple_case(t_list **stack_a, t_list **stack_b,
		t_list *last)
{
	if ((*stack_b)->number < (*stack_a)->number)
		while ((*stack_b)->number < (*stack_a)->number)
			rra(stack_a);
	else
		while ((*stack_b)->number > (*stack_a)->number)
			ra(stack_a);
	last = ft_listlast(*stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->number < last->number)
	{
		while ((*stack_a)->number < last->number)
		{
			ra(stack_a);
			last = ft_listlast(*stack_a);
		}
	}
	else
	{
		while ((*stack_a)->number > last->number)
		{
			rra(stack_a);
			last = ft_listlast(*stack_a);
		}
	}
}

void	ft_free_list(t_list **list)
{
	t_list	*prev;
	t_list	*current;

	if (list != NULL)
	{
		current = *list;
		prev = *list;
		while (current)
		{
			current = current->next;
			free(prev);
			prev = current;
		}
	}
	free(list);
}
