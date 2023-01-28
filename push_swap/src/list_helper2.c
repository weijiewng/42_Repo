/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:58:53 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:38 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_listremove_front(t_list **list)
{
	t_list	*tmp;

	if (list == NULL || *list == NULL)
		return ;
	tmp = (*list)->next;
	(*list)->next = NULL;
	free(*list);
	*list = tmp;
}

void	ft_listremove_back(t_list *list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (list == NULL)
		return ;
	tmp = list;
	while (tmp->next != NULL && tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp->next;
	free(tmp2);
	tmp->next = NULL;
}

int	ft_listget_min(t_list *list)
{
	t_list	*current;
	int		min;

	current = list;
	min = list->number;
	while (current)
	{
		if (current->number < min)
			min = current->number;
		current = current->next;
	}
	return (min);
}

int	ft_listget_listindex(t_list *list, int number)
{
	t_list	*current;
	int		index;

	current = list;
	index = 0;
	while (current)
	{
		if (current->number == number)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}
