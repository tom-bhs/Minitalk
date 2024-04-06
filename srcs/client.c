/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:38:11 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/05 22:15:28 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - 48;
		str++;
	}
	return (result * sign);
}

void	check_arguments(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("You need : %s <PID> <Message>\n", argv[0]);
		exit(0);
	}
}

void	send_character(int pid, int c)
{
	int	bit;

	bit = FIRST;
	while (1)
	{
		if ((c & bit) >= 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		if (bit == 1)
			break ;
		bit = (bit >> 1);
	}
}

void	send_message(char *s_pid, char *message)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(s_pid);
	while (message[i])
		send_character(pid, message[i++]);
	send_character(pid, '\n');
}

int	main(int argc, char **argv)
{
	check_arguments(argc, argv);
	send_message(argv[1], argv[2]);
	return (0);
}
