/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:54:48 by lfornio           #+#    #+#             */
/*   Updated: 2021/09/27 18:01:59 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
// int dec;

void print_signal(int sig)
{
	static char ch = 0;
	static int dec = 128;
	// while (ch)
	// {
	// 	if (ch & 1)
	// 		printf("1");
	// 	else
	// 		printf("0");

	// 	ch >>= 1;
	// }
	// printf("sig = %d\n", sig);
	if (dec > 0)
	{
		if (sig == SIGUSR1)
			{
				ch = ch + dec;
				// printf("dec = %d\n", dec);
			}

		dec /= 2;
		// printf("dec2 = %d\n", dec);
	}
	if (dec == 0)
	{
		write(1, &ch, 1);
		if (ch == '\n')
			write(1, "Allo", 1);
		// write(1, "\n", 1);
		ch = 0;
		dec = 128;
	}

		// int dec;
		// dec = 128;
		// while (dec > 0)
		// {
		// 	if (int | dec)
		// 		dec = dec / 2;
		// }
	// 	if (sig == SIGUSR1)
	// 		printf("char\n");
	// printf("sig = %d\n", sig);
	// printf("sigusr1 = %d\n", SIGUSR1);
	// printf("sigusr2 = %d\n", SIGUSR2);

	// c = c

	// printf("sig | dec = %d\n", sig | 128);

	// static char	c = 0;
	// static int	dec = 128;

	// if (dec > 0)
	// {
	// 	if (sig == SIGUSR1)
	// 		c = c + dec;
	// 	dec /= 2;
	// }
	// if (dec == 0)
	// {
	// 	write(1, &c, 1);
	// 	c = 0;
	// 	dec = 128;
	// }
	// exit(0);
}

int main(void)
{
	printf("PID: %d\n", getpid());

	while (1)
	{signal(SIGUSR1, print_signal);
	signal(SIGUSR2, print_signal);

		pause();
	}
	// write(1, "\n", 1);
}
