/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:35:55 by wewang            #+#    #+#             */
/*   Updated: 2022/11/28 13:27:01 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_printf("Could not send data! Aborting service!\n");
		exit(EXIT_FAILURE);
	}
}

void	sender(char c, int pid)
{
	int	i;

	i = 128;
	while (i)
	{
		if (c & i)
			handle_sigusr(pid, SIGUSR1);
		else
			handle_sigusr(pid, SIGUSR2);
		i >>= 1;
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Wrong number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			sender(argv[2][i], pid);
			i++;
		}
	}
	return (0);
}
