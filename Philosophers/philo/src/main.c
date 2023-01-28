/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:37:04 by wewang            #+#    #+#             */
/*   Updated: 2023/01/28 14:35:53 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philo	*ft_handle_arguments(int argc, const char *argv[], t_data *data)
{
	t_philo	*philo;

	if (ft_check_int(argv[1]) && ft_check_int(argv[2]) && ft_check_int(argv[3])
		&& ft_check_int(argv[4]))
	{
		data->number_of = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6 && !ft_check_int(argv[5]))
			return (NULL);
		else if (argc == 6 && ft_check_int(argv[5]))
			data->times_must_eat = ft_atoi(argv[5]);
		if (!ft_init_mutex(data))
			return (NULL);
		philo = ft_init_philo(data);
		if (philo == NULL)
			return (NULL);
		if (ft_start(philo, data))
			return (philo);
	}
	return (NULL);
}

void	ft_check(t_philo *philo, t_data *data)
{
	int			i;
	long long	current;

	while (!data->died && data->all_eat != data->number_of)
	{
		i = 0;
		while (i < data->number_of)
		{
			current = ft_time_ms();
			if (philo[i].times_eat != data->times_must_eat
				&& data->time_to_die < current - (philo[i].last_eat
					+ data->start_time))
			{
				pthread_mutex_lock(&philo->data->m_print);
				data->died = 1;
				printf("%lld Philo %d %s\n", current - philo->data->start_time,
					philo->id, DIE);
				pthread_mutex_unlock(&philo->data->m_print);
				break ;
			}
			i++;
		}
	}
}

void	ft_close(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (data->all_stopped != data->number_of)
		;
	while (i < data->number_of)
	{
		pthread_join(philo[i].philo_thread, NULL);
		i++;
	}
}

int	main(int argc, const char *argv[])
{
	t_data	*data;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	ft_init_data(data);
	philo = NULL;
	if (argc == 5 || argc == 6)
	{
		philo = ft_handle_arguments(argc, argv, data);
		if (philo == NULL)
			return (1);
		ft_check(philo, data);
		ft_close(philo, data);
	}
	ft_free(data, philo);
	return (0);
}
