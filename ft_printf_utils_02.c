/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:53:55 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/06 18:53:08 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f(const char **s, va_list *list, t_var *var)
{
	if (**s == '%')
		ft_percent(&var->count);
	if (**s == 'c')
		ft_character(&var->temp, &var->count, list);
	if (**s == 's')
		ft_string (var->tmp, &var->count, list);
	if (**s == 'p')
		ft_address(var->tmp, &var->count, list);
	if (**s == 'd' || **s == 'i')
		ft_decimal(&var->temp, &var->count, list);
	if (**s == 'u')
		ft_u_decimal(&var->temp, &var->count, list);
	if (**s == 'x')
		ft_hex_low(&var->temp, &var->count, list);
	if (**s == 'X')
		ft_hex_up(&var->temp, &var->count, list);
}

void	ft_hex_low(long long *temp, int *count, va_list *list)
{
	*temp = va_arg(*list, unsigned int);
	if (*temp < 0)
		ft_put_minus(count, temp);
	ft_putn((unsigned long long)(*temp), HEX, 0, count);
}

void	ft_hex_up(long long *temp, int *count, va_list *list)
{
	*temp = va_arg(*list, unsigned int);
	if (*temp < 0)
		ft_put_minus(count, temp);
	ft_putn((unsigned long long)(*temp), HEX, 1, count);
}
