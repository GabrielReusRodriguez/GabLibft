/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 23:46:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "libft.h"

int	ft_printf_usgn(va_list argp)
{
	return (ft_printf_fd_usgn(argp, STDOUT_FILENO));
}

int	ft_printf_fd_usgn(va_list argp, int fd)
{
	unsigned int	arg_value;
	char			*ch_number;

	arg_value = va_arg(argp, unsigned int);
	ch_number = ft_utoa(arg_value);
	if (ch_number != NULL)
		return (-1);
	return (ft_iputstr_fd(ch_number, fd));
}