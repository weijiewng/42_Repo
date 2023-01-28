/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:12:16 by wewang            #+#    #+#             */
/*   Updated: 2023/01/28 15:15:39 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_take_fork(t_philo *philo)
{
	if (philo->data->number_of == 1)
	{
		pthread_mutex_lock(&philo->data->fork[philo->left]);
		if (ft_print_timestamp_with_action(FORK, philo) == -1)
			return (-1);
		pthread_mutex_unlock(&philo->data->fork[philo->left]);
		ft_ms_sleep(philo->data->time_to_die);
		return (-1);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	if (philo->id == 1)
	{
		if (ft_handle_first_fork(philo, philo->right) == -1)
			return (-1);
		return (ft_handle_second_fork(philo, philo->right, philo->left));
	}
	else
	{
		if (ft_handle_first_fork(philo, philo->left) == -1)
			return (-1);
		return (ft_handle_second_fork(philo, philo->left, philo->right));
	}
	return (1);
}

int	ft_handle_first_fork(t_philo *philo, int first)
{
	pthread_mutex_lock(&philo->data->fork[first]);
	if (ft_print_timestamp_with_action(FORK, philo) == -1)
	{
		pthread_mutex_unlock(&philo->data->fork[first]);
		return (-1);
	}
	return (1);
}

int	ft_handle_second_fork(t_philo *philo, int first, int second)
{
	pthread_mutex_lock(&philo->data->fork[second]);
	if (ft_print_timestamp_with_action(FORK, philo) == -1)
	{
		pthread_mutex_unlock(&philo->data->fork[first]);
		pthread_mutex_unlock(&philo->data->fork[second]);
		return (-1);
	}
	return (1);
}
