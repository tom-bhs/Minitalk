/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:38:11 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/24 19:26:05 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"


void	handle_signal(int signal)
{
	printf("Signal %d recu\n", signal);
}


int main(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	printf("Serveur PID: %d\n", getpid());
	while (1)
	{
		// handle_signal(signal);
		// send_char;
		printf("SAAA\n");
		pause();
	}
	return (0);
}