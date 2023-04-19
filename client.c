/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:08:15 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/18 07:54:48 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_null(int pid, int len)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		kill(pid, SIGUSR1);
		usleep(150 + (len / 200));
		i--;
	}
}

static int	send_signal(int pid, char *str, int len)
{
	char	ch;
	int		i;
	int		j;

	j = 0;
	while (str[j])
	{
		ch = str[j];
		i = 0;
		while (i < 8)
		{
			if (((ch >> i) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(150 + (len / 200));
		}
		j++;
	}
	if (!str[j])
		send_null(pid, len);
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;

	if (argc < 3 || argc > 3)
		exit (1);
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	if (argc == 3)
		send_signal(pid, argv[2], len);
	return (0);
}
