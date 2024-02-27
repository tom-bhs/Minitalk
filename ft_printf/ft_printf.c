/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:09:00 by tom               #+#    #+#             */
/*   Updated: 2023/11/24 19:55:09 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//sert a calculer la longueur dune chaine de caractere
int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//sert a convertir un nombre en base de donee et renvoie
//la longeur de la chaine convertie 
int	ft_nbrbase(unsigned long nbr, char *base, bool ptr)
{
	unsigned long	size;
	unsigned long	nb;
	int				len;

	len = 0;
	nb = nbr;
	if (ptr)
	{
		if (nbr == 0)
			return (len += ft_putstr("(nil)"));
		len += ft_putstr("0x");
		ptr = 0;
	}
	size = ft_strlen(base);
	if (nb > size -1)
	{
		len += ft_nbrbase(nb / size, base, ptr);
	}
	len += ft_putchar(base[nb % size]);
	return (len);
}

//sert a affiche les donnee en fonction du format specifie 
int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_nbrbase(va_arg(args, unsigned long), "0123456789abcdef",
				true);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr_un(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789abcdef",
				false);
	else if (format == 'X')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789ABCDEF",
				false);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

//parcourt la chaine de "format" et appelle ft_format pour chaque specificaion
//de format rencontree
int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(arguments, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			len += ft_format(arguments, format[i +1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
	}
	va_end(arguments);
	return (len);
}
