/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:43:39 by wewang            #+#    #+#             */
/*   Updated: 2022/12/30 13:27:53 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_listnew(int number, int index)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->index = index;
	new->next = NULL;
	return (new);
}

t_list	*ft_listlast(t_list *list)
{
	t_list	*last;

	if (list == NULL)
		return (NULL);
	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	ft_listsize(t_list *list)
{
	t_list	*current;
	int		i;

	if (list == NULL)
		return (0);
	current = list;
	i = 1;
	while (current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	ft_listadd_front(t_list **list, t_list *new)
{
	if (list != NULL)
	{
		new->next = *list;
		*list = new;
	}
}

void	ft_listadd_back(t_list **list, t_list *new)
{
	t_list	*tmp;

	tmp = *list;
	if (tmp != NULL)
	{
		tmp = ft_listlast(tmp);
		tmp->next = new;
	}
	else
		*list = new;
}
