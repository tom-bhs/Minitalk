/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:26 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/11 18:40:02 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

struct s_Buffer	g_buffer;

void	ft_init_buffer(void)
{
	g_buffer.data = malloc(BUFFER_SIZE);
	if (!g_buffer.data)
	{
		ft_printf("Erreur d'allocation mémoire\n");
		exit(EXIT_FAILURE);
	}
	g_buffer.index = 0;
}

void	ft_clear_buffer(void)
{
	size_t	i;

	i = 0;
	while (i < g_buffer.index)
	{
		g_buffer.data[i] = '\0';
		++i;
	}
	g_buffer.index = 0;
}

void	ft_handler(int signum)
{
	static int				bitsreceived = 0;
	static unsigned char	currentchar = 0;

	if (signum == SIGUSR2)
	{
		currentchar |= (1 << (7 - bitsreceived));
	}
	bitsreceived++;
	if (bitsreceived == 8)
	{
		if (g_buffer.index < BUFFER_SIZE - 1)
		{
			g_buffer.data[g_buffer.index++] = currentchar;
			g_buffer.data[g_buffer.index] = '\0';
		}
		if (currentchar == '\0')
		{
			ft_printf("%s\n", g_buffer);
			ft_clear_buffer();
		}
		bitsreceived = 0;
		currentchar = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_init_buffer();
	sa.sa_handler = ft_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
