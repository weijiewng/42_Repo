/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:54 by wewang            #+#    #+#             */
/*   Updated: 2023/02/02 17:01:12 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_eat(t_philo *philo)
{
	if (ft_take_fork(philo) == -1)
		return (-1);
	pthread_mutex_lock(&(philo->m_last_eat));
	philo->last_eat = ft_print_timestamp_with_action(EAT, philo);
	if (philo->last_eat == -1)
	{
		pthread_mutex_unlock(&(philo->m_last_eat));
		return (-1);
	}
	pthread_mutex_unlock(&(philo->m_last_eat));
	ft_ms_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->fork[philo->left]);
	pthread_mutex_unlock(&philo->data->fork[philo->right]);
	pthread_mutex_lock(&(philo->m_times_eat));
	philo->times_eat++;
	pthread_mutex_unlock(&(philo->m_times_eat));
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_print_timestamp_with_action(SLEEP, philo) == -1)
		return (-1);
	ft_ms_sleep(philo->data->time_to_sleep);
	return (1);
}

void	*ft_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!ft_check_died(philo->data))
	{
		if (ft_eat(philo) == -1)
			break ;
		if (ft_check_times_eat(philo))
		{
			pthread_mutex_lock(&(philo->data->m_all_eat));
			philo->data->all_eat++;
			pthread_mutex_unlock(&(philo->data->m_all_eat));
			break ;
		}
		if (ft_sleep(philo) == -1)
			break ;
		if (ft_print_timestamp_with_action(THINK, philo) == -1)
			break ;
		usleep(400);
	}
	pthread_mutex_lock(&(philo->data->m_all_stopped));
	philo->data->all_stopped++;
	pthread_mutex_unlock(&(philo->data->m_all_stopped));
	return (NULL);
}

int	ft_start(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	data->start_time = ft_time_ms();
	while (i < data->number_of)
	{
		if (pthread_create(&(philo[i].philo_thread), NULL, &ft_routine,
				&philo[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
