/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_up_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:46 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/13 00:02:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "libft.h"


int	ft_printf_fd_up_hex(va_list argp, int fd)
{
	unsigned int	arg;
	char			*hex_number;

	arg = va_arg(argp, unsigned int);
	hex_number = ft_printf_htoa(arg);
	if (hex_number == NULL)
		return (-1);
	return (ft_iputstr_fd(hex_number, fd));
}


int	ft_printf_up_hex(va_list argp)
{
	unsigned int	arg;
	char			*hex_number;

	arg = va_arg(argp, unsigned int);
	return (ft_printf_fd_up_hex(argp, STDOUT_FILENO));
}
