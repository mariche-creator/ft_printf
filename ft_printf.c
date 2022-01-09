/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:20:59 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/06 18:45:22 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	list;
	t_var	var;

	var.count = 0;
	var.tmp = 0;
	va_start(list, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			f(&s, &list, &var);
		}
		else
		{
			write(1, s, 1);
			var.count++;
		}
		s++;
	}
	va_end(list);
	return (var.count);
}
