/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:12:21 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/09 10:39:02 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	acknowledgement(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("from the server!!");
}

void	send_to_server(pid_t pid, char *binary)
{
	int	index;

	index = 0;
	while (*(binary + index))
	{
		if (*(binary + index) == '1')
			kill(pid, SIGUSR1);
		else if (*(binary + index) == '0')
			kill(pid, SIGUSR2);
		index++;
		usleep(200);
	}
}

void	null_terminating(pid_t pid)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		kill(pid, SIGUSR2);
		index++;
		usleep(200);
	}
}

void	encrypt_message_and_send(char *string, pid_t pid)
{
	int		iter;
	int		i;
	char	bit;
	char	byte[9];

	i = 0;
	while (*(string + i))
	{
		iter = 7;
		while (iter >= 0)
		{
			bit = (*(string + i) >> iter) & 1;
			if (bit == 1)
				byte[7 - iter] = '1';
			else
				byte[7 - iter] = '0';
			iter--;
		}
		byte[7 - iter] = '\0';
		send_to_server(pid, byte);
		i++;
	}
	null_terminating(pid);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid;

	if (ac == 3)
	{
		sa.sa_handler = &acknowledgement;
		sigaction(SIGUSR1, &sa, NULL);
		pid = ft_atoi(av[1]);
		encrypt_message_and_send(av[2], pid);
	}
	else
		ft_printf("insufficient arguments!!\n");
	return (0);
}
