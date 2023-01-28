/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:35:36 by wewang            #+#    #+#             */
/*   Updated: 2023/01/28 14:35:41 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_data
{
	int				number_of;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				all_eat;
	int				died;
	long long		start_time;
	int				all_stopped;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_all_eat;
	pthread_mutex_t	m_all_stopped;
	pthread_mutex_t	*fork;
}					t_data;

typedef struct s_philo
{
	pthread_t		philo_thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat;
	int				times_eat;
	struct s_data	*data;
}					t_philo;

/*
		init.c
*/
int					ft_init_mutex(t_data *data);
t_philo				*ft_init_philo(t_data *data);

/*
		utils.c
*/
int					ft_atoi(char const *nptr);
int					ft_check_int(const char *str);
void				ft_free(t_data *data, t_philo *philo);
void				ft_init_data(t_data *data);
/*
		print_time.c
*/
void				ft_print_error(void);
void				ft_ms_sleep(long long ms);
long long			ft_time_ms(void);
long long			ft_print_timestamp_with_action(char *message,
						t_philo *philo);

/*
		philo_tasks.c
*/
int					ft_eat(t_philo *philo);
int					ft_sleep(t_philo *philo);
void				*ft_routine(void *ptr);
int					ft_start(t_philo *philo, t_data *data);

/*
		take_fork.c 
*/

int					ft_take_fork(t_philo *philo);
int					ft_handle_first_fork(t_philo *philo, int first);
int					ft_handle_second_fork(t_philo *philo, int first,
						int second);
#endif