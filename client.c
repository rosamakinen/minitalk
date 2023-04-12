/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:08:15 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/12 07:01:07 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	send_signal(int pid, char *str)
{
	char	ch;
	int		i;
	int		j;

	j = 0;

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
			}
			else
			{
				kill(pid, SIGUSR2);
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
		send_signal(pid, argv[2]);
	}
	return (0);
}
