/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:26 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/21 18:48:43 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minitalk.h"

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// void	send_request()
// {
	// 
// }

void	sigusr1(int sig)
{
	write(1, "SIGUSR1 recu\n", 10);
}

void	sigusr2(int sig)
{
	write(1, "SIGUSR2 recu\n", 10);
}


int main()
{
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);


	printf("Serveur PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}