/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:26 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/10 16:51:02 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

struct Buffer {
	char *data;
	size_t index;
};

struct Buffer buffer;


void	init_buffer(void)
{
	buffer.data = malloc(BUFFER_SIZE);
	if (!buffer.data)
	{
		ft_printf("Erreur d'allocation mémoire\n");
		exit(EXIT_FAILURE);
	}
	buffer.index = 0;
}

void	clear_buffer(void)
{
	size_t	i;

	i = 0;
	while (i < buffer.index)
	{
		buffer.data[i] = '\0';
		++i;
	}
	buffer.index = 0;
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
		if (buffer.index < BUFFER_SIZE - 1)
		{
			buffer.data[buffer.index++] = currentchar;
			buffer.data[buffer.index] = '\0';
		}
		else
		{
			ft_printf("Buffer plein. Message tronqué : %s\n", buffer);
			clear_buffer();
		}
		if (currentchar == '\0')
		{
			ft_printf("%s\n", buffer);
			clear_buffer();
		}
		bitsreceived = 0;
		currentchar = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	init_buffer();
	sa.sa_handler = ft_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
