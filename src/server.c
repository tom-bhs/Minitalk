/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:38:11 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/03 22:26:46 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	check_signal(int signal)
{
	static int		bits = 0;
	static char		character = 0;

	if (signal == SIGUSR1)
		character <<= 1;
	else if (signal == SIGUSR2)
		character = (character << 1) | 1;
	bits++;
	if (bits == BIT_COUNT)
	{
		ft_printf(&character, 1);
		bits = 0;
		character = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, check_signal);
	signal(SIGUSR2, check_signal);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
