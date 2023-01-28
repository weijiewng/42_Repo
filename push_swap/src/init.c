/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:12:49 by wewang            #+#    #+#             */
/*   Updated: 2023/01/10 11:57:45 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_check_duplicates(t_list *stack_a)
{
	t_list	*start;
	t_list	*list_tmp;

	if (stack_a == NULL)
		return (0);
	start = stack_a;
	while (start->next)
	{
		list_tmp = start->next;
		while (list_tmp)
		{
			if (start->number == list_tmp->number)
				return (0);
			list_tmp = list_tmp->next;
		}
		start = start->next;
	}
	return (1);
}

int	ft_check_sign(char *str)
{
	if ((str[0] == '-' || str[0] == '+') && !ft_isdigit(str[1]))
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			return (-1);
		return (1);
	}
	if (ft_isdigit(str[0]))
		return (2);
	return (0);
}

int	ft_check_int(char *str)
{
	long	number;
	int		i;
	int		minus;

	number = 0;
	i = 0;
	if (!str)
		return (0);
	minus = ft_check_sign(str);
	if (minus == 0)
		return (0);
	if (minus == 1 || minus == -1)
		i++;
	if (minus == 2)
		minus = 1;
	while (str[i] && i < 11)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	if (number * minus > INT_MAX || number * minus < INT_MIN)
		return (0);
	return (1);
}

int	ft_fill_stack_a(int argc, char *argv[], t_list **stack_a)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	**split;

	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			if (!ft_check_int(split[j]))
			{
				ft_free_split(split);
				return (0);
			}
			tmp = ft_listnew(ft_atoi(split[j]), -1);
			ft_listadd_back(stack_a, tmp);
			j++;
		}
		i++;
		ft_free_split(split);
	}
	return (ft_check_duplicates(*stack_a));
}
