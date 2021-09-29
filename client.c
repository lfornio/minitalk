/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:56:40 by lfornio           #+#    #+#             */
/*   Updated: 2021/09/29 12:57:13 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	pid_error(char *str)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			flag++;
		else
			return (0);
		i++;
	}
	return (1);
}

static void	send_str(t_pid pid, char *str)
{
	int	i;
	int	rank;
	int	error;

	i = 0;
	while (i <= (int)ft_strlen(str))
	{
		rank = 128;
		while (rank > 0)
		{
			if ((str[i] & rank))
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			if (error == -1)
			{
				ft_putstr("PID not found\n");
				exit(0);
			}
			rank /= 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_pid	pid;

	if (argc == 3)
	{
		if (pid_error(argv[1]) == 0)
			ft_putstr("Invalid PID\n");
		else
		{
			pid = (t_pid)ft_atoi(argv[1]);
			send_str(pid, argv[2]);
		}
	}
	else
		ft_putstr("Arguments error\n");
	return (0);
}
