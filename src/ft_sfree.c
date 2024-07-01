/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:27:23 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/01 21:07:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_sfree(size_t num_ptrs, ...)
{
	va_list	args;
	void	*ptr;
	size_t	i;

	i = 0;
	va_start(args, num_ptrs);
	while (i < num_ptrs)
	{
		ptr = va_arg(args, void *);
		if (ptr != NULL)
			free (ptr);
		i++;
	}
	va_end(args);
}
