/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:26 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/22 19:34:56 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void	handle_signal(int signal __attribute__((unused)))
{
	printf("Signal %d recu\n", signal);
}

void	send_char_signal(pid_t pid)
{
	if (kill(pid, SIGUSR1) == -1)
	{
		perror("Erreur d'envoie de SIGUSR1");
		exit(EXIT_FAILURE);
	}
}

//mon serveur
void	sigusr2(int sig __attribute__((unused)))
{
	write(1, "SIGUSR2 recu\n", 13);
		write(1, "2\n", 2);
}

// void	send_string(pid_t pid, const char* message) 
// {
//     while (*message)
// 	{
//         send_char_signal(pid);
//         usleep(100000);
// 	}
// }


int main()
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	printf("Serveur PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
