/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:26:57 by wewang            #+#    #+#             */
/*   Updated: 2023/01/02 12:56:17 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_handle_list(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!ft_check_sorted(*stack_a))
	{
		size = ft_listsize(*stack_a);
		if (size == 2)
			ft_handle_2_numbers(stack_a);
		else if (size == 3)
			while (!ft_handle_3_numbers(stack_a))
				;
		else if (size == 4)
			ft_handle_4_numbers(stack_a, stack_b);
		else if (size == 5)
			ft_handle_5_numbers(stack_a, stack_b);
		else
			ft_handle_big_list(stack_a, stack_b);
	}
}

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc > 1)
	{
		stack_a = (t_list **)malloc(sizeof(t_list));
		stack_b = (t_list **)malloc(sizeof(t_list));
		if (stack_a == NULL || stack_b == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		*stack_a = NULL;
		*stack_b = NULL;
		if (ft_fill_stack_a(argc, argv, stack_a))
			ft_handle_list(stack_a, stack_b);
		else
			ft_putstr_fd("Error\n", 2);
		ft_free_list(stack_a);
		ft_free_list(stack_b);
	}
	return (1);
}
