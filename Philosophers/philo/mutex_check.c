/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:12:39 by wewang            #+#    #+#             */
/*   Updated: 2023/01/30 17:23:25 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_still_alive(t_philo *philo, t_data *data, long long current)
{
	pthread_mutex_lock(&(philo->m_times_eat));
	pthread_mutex_lock(&(philo->m_last_eat));
	current = ft_time_ms();
	if (philo->times_eat != data->times_must_eat && data->time_to_die < current
		- (philo->last_eat + data->start_time))
	{
		pthread_mutex_unlock(&(philo->m_last_eat));
		pthread_mutex_unlock(&(philo->m_times_eat));
		return (0);
	}
	pthread_mutex_unlock(&(philo->m_last_eat));
	pthread_mutex_unlock(&(philo->m_times_eat));
	return (1);
}

int	ft_check_died(t_data *data)
{
	pthread_mutex_lock(&(data->m_died));
	if (data->died == 1)
	{
		pthread_mutex_unlock(&(data->m_died));
		return (1);
	}
	pthread_mutex_unlock(&(data->m_died));
	return (0);
}

int	ft_check_times_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_times_eat));
	if (philo->times_eat == philo->data->times_must_eat)
	{
		pthread_mutex_unlock(&(philo->m_times_eat));
		return (1);
	}
	pthread_mutex_unlock(&(philo->m_times_eat));
	return (0);
}

int	ft_check_all_eat(t_data *data)
{
	pthread_mutex_lock(&(data->m_all_eat));
	if (data->all_eat == data->number_of)
	{
		pthread_mutex_unlock(&(data->m_all_eat));
		return (1);
	}
	pthread_mutex_unlock(&(data->m_all_eat));
	return (0);
}

int	ft_check_all_stopped(t_data *data)
{
	pthread_mutex_lock(&(data->m_all_stopped));
	if (data->all_stopped == data->number_of)
	{
		pthread_mutex_unlock(&(data->m_all_stopped));
		return (1);
	}
	pthread_mutex_unlock(&(data->m_all_stopped));
	return (0);
}
