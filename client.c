/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:13:21 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/06 10:21:34 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void    acknowledgement(int signum)
{
	if(signum == SIGUSR1)
		ft_printf("from the server!!");
}

char    *encrypt_message(char *string)
{
	int		index;
	int		iter;
	int		len;
	int     i;
	char    bit;
	char    *binary;

	i = 0;
	index = 0;
	len = ft_strlen(string);
	binary = malloc(sizeof(char) * ((len * 8) + 1));
	if(!binary)
		return (NULL);
	while (*(string + i))
	{
		iter = 7;
		while(iter >= 0)
		{
			bit = (*(string + i) >> iter) & 1;
			if (bit == 1)
				*(binary + index) = '1';
			else
				*(binary + index) = '0';
			index++;
			iter--;
		}
		i++;
	}
	*(binary + index) = '\0';
	return (binary);
}

void	send_to_server(pid_t pid, char *binary)
{
    int indexD = 0;
    while (*(binary + indexD))
    {
        if (*(binary + indexD) == '1')
            kill(pid, SIGUSR1);
        else if (*(binary + indexD) == '0')
            kill(pid, SIGUSR2);
        indexD++;
        usleep(200);
    }
    free(binary);
    binary = NULL;
}

void	null_terminating(pid_t pid)
{
	int	indexD;

	indexD = 0;
	while (indexD < 8)
	{
		kill(pid, SIGUSR2);
		indexD++;
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid;
	char				*binary;
	
	if (ac == 3)
	{
		sa.sa_handler = &acknowledgement;
		sigaction(SIGUSR1, &sa, NULL);
		pid = ft_atoi(av[1]);
		binary = encrypt_message(av[2]);
		send_to_server(pid, binary);
		null_terminating(pid);
	}
	else
		ft_printf("insufficient arguments!!\n");
	return (0);
}
