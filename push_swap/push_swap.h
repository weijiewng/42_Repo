/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:08:29 by wewang            #+#    #+#             */
/*   Updated: 2023/01/02 13:07:30 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next;
}					t_list;

int					ft_check_duplicates(t_list *stack_a);
int					ft_check_sign(char *str);
int					ft_check_int(char *str);
int					ft_fill_stack_a(int argc, char *argv[], t_list **stack_a);
t_list				*ft_listnew(int number, int index);
t_list				*ft_listlast(t_list *list);
int					ft_listsize(t_list *list);
void				ft_listadd_front(t_list **list, t_list *new);
void				ft_listadd_back(t_list **list, t_list *new);
void				ft_listremove_front(t_list **list);
void				ft_listremove_back(t_list *list);
int					ft_listget_min(t_list *list);
int					ft_listget_listindex(t_list *list, int number);
void				ft_index_list(t_list *sorted_list, t_list *stack_a);
int					ft_get_max_bits(t_list *stack_a);
void				ft_redix_sort(t_list **stack_a, t_list **stack_b);
void				ft_handle_big_list(t_list **stack_a, t_list **stack_b);
void				ft_handle_2_numbers(t_list **stack_a);
int					ft_handle_3_numbers(t_list **stack_a);
void				ft_handle_4_numbers(t_list **stack_a, t_list **stack_b);
void				ft_handle_5_numbers(t_list **stack_a, t_list **stack_b);
t_list				*ft_get_tmp_stack(t_list **stack_a, t_list *sorted_list);
t_list				*ft_sort_tmp_stack(t_list *sorted_list);
void				ft_swap(int *a, int *b);
int					ft_check_sorted(t_list *list);
void				ft_free_list(t_list **list);
void				ft_handle_special_simple_case(t_list **stack_a,
						t_list **stack_b,
						t_list *last);
void				sa(t_list *list_a);
void				sb(t_list *list_a);
void				ss(t_list *list_a, t_list *list_b);
void				pa(t_list **list_a, t_list **list_b);
void				pb(t_list **list_a, t_list **list_b);
void				ra(t_list **list_a);
void				rb(t_list **list_b);
void				rr(t_list **list_a, t_list **list_b);
void				rra(t_list **list_a);
void				rrb(t_list **list_b);
void				rrr(t_list **list_a, t_list **list_b);
#endif