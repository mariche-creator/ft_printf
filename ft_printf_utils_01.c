/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:20 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/06 18:50:44 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putn(unsigned long long n, unsigned int base, short up, int *count)
{
	if (n >= base)
		m_b(&n, base, up, &count);
	else
		l_b(&n, base, up, &count);
}

void	m_b(unsigned long long *n, unsigned int base, short up, int **count)
{
	if (base == 16 && up != 1)
	{
		ft_putn(*n / base, base, 0, *count);
		write(1, &BASE_HEX[*n % base], 1);
		**(count) += 1;
	}
	else if (base == 16 && up == 1)
	{
		ft_putn(*n / base, base, 1, *count);
		write(1, &BASE_HEX_U[*n % base], 1);
		**(count) += 1;
	}
	else
	{
		ft_putn(*n / base, base, 0, *count);
		write(1, &BASE_DEC[*n % base], 1);
		**(count) += 1;
	}
}

void	l_b(unsigned long long *n, unsigned int base, short up, int **count)
{
	if (base == 16 && up != 1)
	{
		write(1, &BASE_HEX[*n], 1);
		**(count) += 1;
	}
	else if (base == 16 && up == 1)
	{
		write(1, &BASE_HEX_U[*n], 1);
		**(count) += 1;
	}
	else
	{
		write(1, &BASE_DEC[*n], 1);
		**(count) += 1;
	}
}

void	ft_decimal(long long *temp, int *count, va_list *list)
{
	*temp = va_arg(*list, int);
	if (*temp < 0)
		ft_put_minus(count, temp);
	ft_putn((unsigned long long)(*temp), DEC, 0, count);
}

void	ft_u_decimal(long long *temp, int *count, va_list *list)
{
	*temp = va_arg(*list, unsigned int);
	ft_putn((unsigned long long)(*temp), DEC, 0, count);
}
