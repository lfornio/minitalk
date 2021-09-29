/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:47:13 by lfornio           #+#    #+#             */
/*   Updated: 2021/09/29 13:05:57 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef int	t_pid;
void		ft_putstr(char *s);
int			ft_atoi(const char *str);
void		ft_putnbr(int n);
size_t		ft_strlen(const char *str);

#endif
