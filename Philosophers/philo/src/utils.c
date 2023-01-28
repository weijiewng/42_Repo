/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:36:06 by wewang            #+#    #+#             */
/*   Updated: 2023/01/28 14:26:20 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_atoi(char const *nptr)
{
	int		i;
	int		minus;
	long	res;

	i = 0;
	minus = 1;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
		if (res * minus > INT_MAX)
			return (-1);
		if (res * minus < INT_MIN)
			return (0);
	}
	return (res * minus);
}

int	ft_check_int(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (i > 10)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (data != NULL)
	{
		while (i < data->number_of)
		{
			pthread_mutex_destroy(&(data->fork[i]));
			i++;
		}
		pthread_mutex_destroy(&(data->m_all_eat));
		pthread_mutex_destroy(&(data->m_print));
		pthread_mutex_destroy(&(data->m_all_stopped));
		if (data->fork)
			free(data->fork);
		free(data);
		if (philo)
			free(philo);
	}
}

void	ft_init_data(t_data *data)
{
	data->number_of = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->times_must_eat = -1;
	data->all_eat = 0;
	data->died = 0;
	data->start_time = 0;
	data->all_stopped = 0;
}
