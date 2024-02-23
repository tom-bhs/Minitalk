/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:38:11 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/23 18:59:06 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"


void	handle_signal(int signal)
{
	printf("Signal %d recu\n", signal);
}


void	send_char(int pid, char c)
{
	for (int i = 7; i >= 0; --i)
		{
			int bit = (c >> i) &1;
			verif_bit(bit, pid);
			sleep(2);
		}
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
		// pause();
		printf("SAAA\n");
	}
	return (0);
}