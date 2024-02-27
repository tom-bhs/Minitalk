/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:26 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/27 17:15:58 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	verif_bit(int bit, int pid)
{
	if (bit == 0)
	{
		kill(pid, SIGUSR1);
		ft_printf("0");
	}
	else
	{
		kill(pid, SIGUSR2);
		ft_printf("1");
	}
}

void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		verif_bit(bit, pid);
		usleep(10000);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int			pid;
	const char	*message;

	if (argc != 3)
	{
		ft_printf("You need : %s <PID> <Message>\n", argv[0]);
		return (1);
	}
	pid = atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		send_char(pid, *message);
		message++;
		if (*message == '\0')
			send_char(pid, '\n');
	}
	return (0);
}
