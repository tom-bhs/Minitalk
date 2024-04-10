/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:38:31 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/10 23:32:19 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

struct s_Buffer
{
	char	*data;
	size_t	index;
};

// # define FIRST 0b10000000
// # define LAST 0b00000001

# define BUFFER_SIZE 10000

#endif