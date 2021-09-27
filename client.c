/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:54:37 by lfornio           #+#    #+#             */
/*   Updated: 2021/09/27 17:37:14 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

typedef int t_pid;

int ft_atoi(const char *str);

int pid_error(char *str)
{
	int flag;
	flag = 0;
	int i;
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

void send_str(t_pid pid, char c)
{
	int i;
	int dec;
	// printf("str = %s\n", str);
	// printf("char = %c\n", str[0]);

	i = 0;

		dec = 128;
		while (dec > 0)
		{
			if((c & dec))
			{
				kill(pid, SIGUSR1);
				printf("sigusr2 = %d\n",SIGUSR1);
				printf("1 = %d\n",(c & dec) );
				// return ;
			}
			else
			{
				kill(pid, SIGUSR2);
				printf("sigusr1 = %d\n",SIGUSR2);
				printf("2 = %d\n",(c & dec) );
				// return ;
			}
			dec = dec / 2;
			printf("sig = %d\n", c & dec);
			printf("dec = %d\n", dec);
			// exit(0);
			usleep(100);
		}

		// exit(0);

	}

int main(int argc, char **argv)
{

	t_pid pid;
	char *s;
	int i;
	i = 0;


	if (argc == 3)
	{
		if (pid_error(argv[1]) == 0)
			printf("Error with pid\n");
		else
		{
			pid = (t_pid)ft_atoi(argv[1]);
			s = argv[2];
			while (s[i])
			{
				send_str(pid, s[i]);
				i++;
			}


		}
		// printf("%s\n", argv[2]);
	}
	else
		printf("Error with arguments\n");
}
