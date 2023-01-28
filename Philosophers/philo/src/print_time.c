/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:37:35 by wewang            #+#    #+#             */
/*   Updated: 2023/01/21 11:40:44 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_print_error(void)
{
	printf("Error\n");
}

void	ft_ms_sleep(long long ms)
{
	usleep((ms * 1000));
}

long long	ft_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

long long	ft_print_timestamp_with_action(char *message, t_philo *philo)
{
	long long	ms;

	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->died == 1)
	{
		pthread_mutex_unlock(&philo->data->m_print);
		return (-1);
	}
	ms = ft_time_ms() - philo->data->start_time;
	printf("%lld Philo %d %s\n", ms, philo->id, message);
	pthread_mutex_unlock(&philo->data->m_print);
	return (ms);
}
