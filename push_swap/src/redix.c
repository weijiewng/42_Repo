/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:13:23 by wewang            #+#    #+#             */
/*   Updated: 2023/01/18 13:05:11 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_index_list(t_list *sorted_list, t_list *stack_a)
{
	int		i;
	t_list	*current;
	t_list	*head;

	i = 0;
	head = stack_a;
	while (sorted_list)
	{
		current = head;
		while (current)
		{
			if (current->number == sorted_list->number)
			{
				current->index = i;
				i++;
			}
			current = current->next;
		}
		sorted_list = sorted_list->next;
	}
}

int	ft_get_max_bits(t_list *stack_a)
{
	int	max;
	int	bits;

	bits = 0;
	max = ft_listsize(stack_a);
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_redix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	shifter;
	int	counter;
	int	size;

	max_bits = ft_get_max_bits(*stack_a);
	shifter = 0;
	while (!ft_check_sorted(*stack_a) && shifter < max_bits)
	{
		counter = 0;
		size = ft_listsize(*stack_a);
		while (counter < size)
		{
			if ((((*stack_a)->index >> shifter) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			counter++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		shifter++;
	}
}

void	ft_handle_big_list(t_list **stack_a, t_list **stack_b)
{
	t_list	**sorted_list;

	sorted_list = (t_list **)malloc(sizeof(t_list));
	if (sorted_list == NULL)
		return ;
	*sorted_list = NULL;
	*sorted_list = ft_get_tmp_stack(stack_a, *sorted_list);
	*sorted_list = ft_sort_tmp_stack(*sorted_list);
	ft_index_list(*sorted_list, *stack_a);
	ft_redix_sort(stack_a, stack_b);
	ft_free_list(sorted_list);
}
