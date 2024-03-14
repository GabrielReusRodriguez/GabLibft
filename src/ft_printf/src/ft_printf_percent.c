/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:36 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 23:36:09 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "libft.h"

int	ft_printf_percent()
{
	return(ft_printf_fd_percent(STDOUT_FILENO));
}

int	ft_printf_fd_percent(int fd)
{
	char	character;

	character = '%';
	return (ft_iputchar_fd(character, fd));
}
