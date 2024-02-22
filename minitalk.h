/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:12:20 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/22 19:33:34 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int		main();
//void	sigusr1(int sig __attribute__((unused)));
void	sigusr2(int sig __attribute__((unused)));
void	handle_signal(int signal);
void	send_char_signal(pid_t pid);

#endif