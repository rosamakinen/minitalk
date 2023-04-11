/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:08:15 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/11 16:58:18 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	send_signal(int pid, char *str)
{
	char	ch;
	int		i;
	int		j;

	j = 0;
	//ft_printf("pid: %i\n", pid);
	//ft_printf("str: %s\n", str);
	while (str[j] != '\0')
	{
		ch = str[j];
		i = 0;
		ft_printf("j:%i\n", j);
		while (i < 8)
		{
			if (((ch >> i) &1) == 0)
			{
				kill(pid, SIGUSR1);
				ft_printf("i:%i ", i);
				//ft_printf("sigusr1\n");
			}
			else
			{
				kill(pid, SIGUSR2);
				ft_printf("i:%i ", i);
				//ft_printf("sigusr2\n");
			}
			i++;
			usleep(500);
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc > 1)
	{
		//ft_printf("segcheck");
		send_signal(pid, argv[2]);
	}
	return (0);
}
