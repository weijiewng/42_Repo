/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:12:14 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:50 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_get_tmp_stack(t_list **stack_a, t_list *sorted_list)
{
	t_list	*current;

	current = *stack_a;
	sorted_list = ft_listnew(current->number, current->index);
	while (current->next)
	{
		current = current->next;
		ft_listadd_back(&sorted_list, ft_listnew(current->number,
				current->index));
	}
	return (sorted_list);
}

t_list	*ft_sort_tmp_stack(t_list *sorted_list)
{
	int		sorted;
	t_list	*current;

	sorted = 0;
	while (!sorted)
	{
		current = sorted_list;
		sorted = 1;
		while (current->next)
		{
			if (current->number > current->next->number)
			{
				ft_swap(&current->number, &current->next->number);
				sorted = 0;
			}
			current = current->next;
		}
	}
	return (sorted_list);
}
