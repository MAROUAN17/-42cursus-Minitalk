/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:12:49 by maglagal          #+#    #+#             */
/*   Updated: 2024/01/09 12:06:20 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	g_uni_index = 0;

void	display_unicode(int *isunicode, int *asci_char, int bits)
{
	int			reversed_index;
	static int	unicode[4];

	reversed_index = 0;
	*isunicode = 1;
	unicode[g_uni_index] = *asci_char;
	g_uni_index++;
	if (g_uni_index == bits)
	{
		while (reversed_index < g_uni_index)
		{
			ft_printf("%c", unicode[reversed_index]);
			reversed_index++;
		}
		g_uni_index = 0;
		*isunicode = 0;
	}
}

void	display_character(char *string)
{
	int			i;
	int			bits;
	static int	isunicode = 0;
	int			asci_char;

	i = 0;
	asci_char = 0;
	if (g_uni_index == 0)
		bits = expected_bytes(string);
	while ((*(string + i) == '0' || *(string + i) == '1'))
	{
		asci_char = asci_char * 2 + (*(string + i) - '0');
		i++;
	}
	if (asci_char > 127 || isunicode == 1)
		display_unicode(&isunicode, &asci_char, bits);
	else
		ft_printf("%c", asci_char);
}

void	decrypt_message(int signum, siginfo_t *info, void *context)
{
	static char		byte[9];
	static int		index = 0;
	static pid_t	curr_pid = 0;

	(void)context;
	if (curr_pid != info->si_pid)
	{
		if (info->si_pid != 0)
			curr_pid = info->si_pid;
		index = 0;
		g_uni_index = 0;
	}
	if (signum == SIGUSR1)
		byte[index] = '1';
	else if (signum == SIGUSR2)
		byte[index] = '0';
	index++;
	if (index == 8)
	{
		byte[index] = '\0';
		display_character(byte);
		index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	sigset_t			signals;
	pid_t				pid;

	pid = getpid();
	ft_printf("PID -> %d\n", pid);
	sigemptyset(&signals);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	sa1.sa_mask = signals;
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = decrypt_message;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa1, NULL);
	while (1)
		pause();
	return (0);
}
