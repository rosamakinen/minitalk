/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:38:30 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/11 16:58:17 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *print;

static void	handle_signal(int sig)
{
	static int	bit;
	static char	temp;
	static char	comp;
	static char add[2];
	//static int	i;
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
	add[1] = 0;
	if (bit < 8)
	{
		if (sig == SIGUSR2)
			temp = temp | comp;
	}
	comp = comp >> bit;
	bit++;
	//ft_printf("bit : %i\n", bit);
	if (bit == 8)
	{
		//temp = 'a';
		//add[0] = temp;
		//print = ft_strjoin(print, add);
		ft_printf("%i\n", temp);
		//ft_printf("%s", print);
		bit = 0;
		temp = 0;
		comp = 0;
	}
// 	ft_printf("%i\n", i);
// 	if (sig == SIGUSR1)
// 	{
// 		ft_printf("sigusr1\n");
// 		i++;
// 	}
// 	if (sig == SIGUSR2)
// 	{
// 		ft_printf("sigusr2\n");
// 		i++;
// 	}
}

int	main()
{
	struct sigaction	sa;
	int					pid;

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
