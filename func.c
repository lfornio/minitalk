/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:05:53 by lfornio           #+#    #+#             */
/*   Updated: 2021/09/29 09:44:51 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int	ft_atoi(const char *str)
{
	long	i;
	long	n;
	int		b;

	i = 0;
	n = 0;
	b = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	n = n * b;
	return (n);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(t_pid n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar((n + '0'));
	}
	else
	{
		ft_putnbr((n / 10));
		ft_putchar((n % 10 + '0'));
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
