/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:26:43 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/06 18:49:12 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent(int *count)
{
	write(1, "%", 1);
	*(count) += 1;
}

void	ft_character(long long *temp, int *count, va_list *list)
{
	*temp = va_arg(*list, int);
	write(1, temp, 1);
	*(count) += 1;
}

void	ft_string(char *tmp, int *count, va_list *list)
{
	tmp = va_arg(*list, char *);
	if (tmp == NULL)
	{
		write(1, "(null)", 6);
		*(count) += 6;
	}
	while (tmp != NULL && *tmp != '\0')
	{
		write(1, tmp, 1);
		*(count) += 1;
		tmp++;
	}
}

void	ft_address(char *tmp, int *count, va_list *list)
{
	tmp = va_arg(*list, void *);
	write(1, "0x", 2);
	*(count) += 2;
	ft_putn((unsigned long long)tmp, HEX, 0, count);
}

void	ft_put_minus(int *count, long long *temp)
{
	write(1, "-", 1);
	*(count) += 1;
	*(temp) *= (-1);
}
