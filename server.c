/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:38:30 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/06 14:26:41 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// int	send_signal(int sig)
// {
// 	if (sig == 1)
// 	{
// 		// send sigusr 1 to client
// 	}
// 	else
// 		// send sigusr 2 to client
// }

int	main()
{
	//struct sigaction	sa;
	int					pid;

	//sa.sa_handler = &send_signal;
	pid = getpid();
	//sigaction(SIGUSR1, &sa, NULL);
	//sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID %d", pid);
	//kill(pid, SIGUSR1);
	return (0);
}
