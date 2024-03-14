/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:04:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 23:36:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "libft.h"

int ft_printf_char(va_list argp)
{
    return (ft_printf_fd_char(argp, STDOUT_FILENO));
}

int ft_printf_fd_char(va_list argp, int fd)
{
	unsigned char	character;

	character = va_arg(argp, int);
    return (ft_iputchar_fd(character, fd));
}
