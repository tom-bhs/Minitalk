/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tombihoues <tombihoues@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:26 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/10 03:01:53 by tombihoues       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char *buffer;
size_t bufferIndex = 0;

void init_buffer()
{
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
	{
		ft_printf("Erreur d'allocation mémoire\n");
		exit(EXIT_FAILURE);
	}
}

void clear_buffer()
{
	for (size_t i = 0; i < bufferIndex; ++i) // une boucle while 
	{
		buffer[i] = '\0';
	}
	bufferIndex = 0;
}

void ft_handler(int signum)
{
	static int bitsReceived = 0;
	static unsigned char currentChar = 0;

	if (signum == SIGUSR2)
	{
		currentChar |= (1 << (7 - bitsReceived));
	}
	bitsReceived++;

	if (bitsReceived == 8)
	{
		if (bufferIndex < BUFFER_SIZE - 1)
		{
			buffer[bufferIndex++] = currentChar;
			buffer[bufferIndex] = '\0';
		}
		else
		{
			ft_printf("Buffer plein. Message tronqué : %s\n", buffer);
			clear_buffer();
		}
		if (currentChar == '\0')
		{
			ft_printf("%s\n", buffer);
			clear_buffer();
		}

		bitsReceived = 0;
		currentChar = 0;
	}
}

int main(void)
{
	struct sigaction sa;

	init_buffer();

	sa.sa_handler = ft_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("Server PID: %d\n", getpid());

	while (1)
		pause();
	return 0;
}
