/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:32:05 by wewang            #+#    #+#             */
/*   Updated: 2023/01/30 15:49:34 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->number_of);
	if (data->fork == NULL)
		return (0);
	while (i < data->number_of)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&(data->m_died), NULL) != 0)
		return (0);
	if (pthread_mutex_init(&(data->m_print), NULL) != 0)
		return (0);
	if (pthread_mutex_init(&(data->m_all_eat), NULL) != 0)
		return (0);
	if (pthread_mutex_init(&(data->m_all_stopped), NULL) != 0)
		return (0);
	return (1);
}

void	ft_init_philo_static_data(t_philo *philo, t_data *data, int i)
{
	philo->last_eat = 0;
	philo->times_eat = 0;
	philo->id = i + 1;
	philo->left = i;
	philo->data = data;
	if (data->number_of == 1)
		return ;
	if (i == data->number_of - 1)
		philo->right = 0;
	else
		philo->right = i + 1;
}

t_philo	*ft_init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->number_of);
	if (philo == NULL)
		return (NULL);
	while (i < data->number_of)
	{
		ft_init_philo_static_data(&(philo[i]), data, i);
		if (pthread_mutex_init(&(philo[i].m_last_eat), NULL) != 0)
			return (NULL);
		if (pthread_mutex_init(&(philo[i].m_times_eat), NULL) != 0)
			return (NULL);
		i++;
	}
	return (philo);
}
