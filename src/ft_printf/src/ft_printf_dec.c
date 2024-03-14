/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:13:27 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 23:43:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	t_printf_dec(va_list argp)
{
	return (ft_printf_fd_dec(argp, STDOUT_FILENO));
}

int	t_printf_fd_dec(va_list argp, int fd)
{
	return (ft_printf_int(argp, fd));
}
