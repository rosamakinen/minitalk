/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:38:30 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/12 07:01:08 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *print;

static void	handle_signal(int sig)
{
	static int	bit;
	static char	temp;
	char		add[2];

	// 0000 0000 (temp)

	// 0000 0001 (1)
	// when bit = 0. sigusr1
	// when bit = 1, sigusr2
	// 0000 0001 (1) << bit(1)   ->  0000 0010
	// 	temp = temp | bitshiftedone

	// when bit = 2, sigusr2
	// 0000 0001 << 2	-> 0000 0100
	// temp = temp | shiftone
	// temp = temp | shiftone
	// temp |= shiftone
	// 0000 0010 | 0000 0100 == 0000 0110
	add[1] = '\0';
	if (bit < 8)
	{
		if (sig == SIGUSR2)
			temp = temp | (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		add[0] = temp;
		print = ft_strjoin(print, add);
		ft_printf("%s", print);
		bit = 0;
		temp = 0;
	}
}

int	main()
{
	struct sigaction	sa;
	int					pid;

	print = malloc(sizeof(char) * 1);
	pid = getpid();
	ft_printf("PID %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
