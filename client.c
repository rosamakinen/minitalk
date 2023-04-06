/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:08:15 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/06 16:17:29 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_signal(int sig)
{


}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	int	pid;
	int	i;

	sa.sa_handler = &send_signal;
	if (argc > 1)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (i <= argc)
		{
			ft_printf("pid is: %d\n", pid);
			ft_printf("str is: %s\n", argv[i]);
			i++;
		}
		kill(pid, SIGUSR1);
	}
	return (0);
}
