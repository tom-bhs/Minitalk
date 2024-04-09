/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:38:11 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/09 17:26:02 by tbihoues         ###   ########.fr       */
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

void send_char(int pid, unsigned char c)
{
    int bitIndex = 0;
    while (bitIndex < 8)
	{
        int bit = (c >> (7 - bitIndex)) & 1;
        if (bit) {
            kill(pid, SIGUSR2);
        } else {
            kill(pid, SIGUSR1);
        }
        usleep(200);
        bitIndex++;
    }
}

void send_message(int pid, const char *message)
{
	while (*message)
	{
		send_char(pid, *message++);
	}
	send_char(pid, '\0');
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <Message>\n", argv[0]);
		return 1;
	}
	int pid = atoi(argv[1]);
	send_message(pid, argv[2]);
	
	return 0;
}