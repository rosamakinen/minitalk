/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:38:30 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/18 08:25:52 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_print;

static void	free_and_check(char *to_free, char *check)
{
	free(to_free);
	if (!check)
		exit (1);
}

static void	print_signal(void)
{
	ft_printf("%s", g_print);
	free(g_print);
	g_print = ft_strdup("");
	if (!g_print)
		exit(1);
}

static void	handle_signal(int sig)
{
	static int	bit;
	static char	temp;
	char		*temp_s;

	temp_s = NULL;
	if (bit < 8)
	{
		if (sig == SIGUSR2)
			temp = temp | (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		if (ft_strcmp(&temp, "") == 0)
			print_signal();
		else
		{
			temp_s = ft_strdup(g_print);
			free_and_check(g_print, temp_s);
			g_print = ft_strjoin(temp_s, &temp);
			free_and_check(temp_s, g_print);
		}
		bit = 0;
		temp = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	g_print = malloc(sizeof(char *));
	if (g_print == NULL)
		return (0);
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
