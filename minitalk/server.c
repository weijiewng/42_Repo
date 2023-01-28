/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:53:29 by wewang            #+#    #+#             */
/*   Updated: 2022/12/02 13:02:18 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	g_message;

void	handler(int signal)
{
	g_message.bit_shifter++;
	g_message.character <<= 1;
	if (signal == SIGUSR1)
		g_message.character += 1;
	if (g_message.bit_shifter == 8)
	{
		write(1, &g_message.character, 1);
		g_message.bit_shifter = 0;
		g_message.character = 0;
	}
}

int	main(void)
{
	int	pid;

	g_message.bit_shifter = 0;
	g_message.character = 0;
	pid = getpid();
	ft_printf("pid: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
