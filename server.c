/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:55:22 by lfornio           #+#    #+#             */
/*   Updated: 2021/09/29 12:56:19 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_signal(int signum, siginfo_t *sig, void *context)
{
	static char	ch = 0;
	static int	rank = 128;

	(void)context;
	(void)sig;
	if (rank > 0)
	{
		if (signum == SIGUSR1)
			ch = ch + rank;
		rank /= 2;
	}
	if (rank == 0)
	{
		if (ch == 0)
			write(1, "\n", 1);
		write(1, &ch, 1);
		ch = 0;
		rank = 128;
	}
}

int	main(void)
{
	struct sigaction	signal;
	t_pid				pid;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = print_signal;
	ft_putstr("PID: ");
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
	}
}
