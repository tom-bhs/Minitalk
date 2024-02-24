/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:26 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/24 20:25:12 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	verif_bit(int bit, int pid)
{
	if (bit == 0)
	{
		kill(pid, SIGUSR1);
		printf("bon (1)\n");
	}
	else
	{
		kill(pid, SIGUSR2);
		printf("pas bon (2)\n");
	}
}

void	send_char(int pid, char c)
{
	for (int i = 7; i >= 0; --i)
		{
			int bit = (c >> i) &1;
			verif_bit(bit, pid);
			sleep(5);
		}
}

int		main(int argc, char *argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "Il faut : %s <PID> <Message>\n", argv[0]);
		return (1);
	}

	int pid = atoi(argv[1]);
	const char *message = argv[2];


	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	return (0);
}
