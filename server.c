/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:38:30 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/12 10:25:05 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *print;

static void	handle_signal(int sig)
{
	static int	bit;
	static char	temp;

	if (bit < 8)
	{
		if (sig == SIGUSR2)
			temp = temp | (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		if(ft_strcmp(&temp, "") == 0)
		{
			ft_printf("%s", print);
		}
		print = ft_strjoin(print, &temp);

		bit = 0;
		temp = 0;
	}
}

int	main()
{
	struct sigaction	sa;
	int					pid;

	print = malloc(sizeof(char) * 2);
	if (print == NULL)
		return (0);
	pid = getpid();
	ft_printf("PID %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	free(print);
	while (1)
		pause();
	return (0);
}
