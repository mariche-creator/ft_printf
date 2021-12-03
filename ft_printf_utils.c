/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:26:43 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/03 17:27:49 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putnbr(unsigned long long n, unsigned int base, short up, int *count)
{
    if (n >= base)
    {
        if (base == 16 && up != 1)
        {
            ft_putnbr(n / base, base, 0, count);
            write(1, &BASE_HEX[n % base], 1);
            *(count) += 1;
        }
        else if (base == 16 && up == 1)
        {
            ft_putnbr(n / base, base, 1, count);
            write(1, &BASE_HEX_U[n % base], 1);
            *(count) += 1;
        }
        else
        {
            ft_putnbr(n / base, base, 0, count);
            write(1, &BASE_DEC[n % base], 1);
            *(count) += 1;
        }
    }
    else
    {
        if (base == 16 && up != 1)
        {
            write(1, &BASE_HEX[n], 1);
            *(count) += 1;
        }
		else if (base == 16 && up == 1)
		{
			write(1, &BASE_HEX_U[n], 1);
			*(count) += 1;
		}
        else
        {
            write(1, &BASE_DEC[n], 1);
            *(count) += 1;
        }
    }
}

void	ft_percent(int *count)
{
	write(1, "%", 1);
	*(count) += 1;
}

void	ft_character(long long *temp, int *count)
{
	write(1, temp, 1);
	*(count) += 1;
}

void	ft_string(char *tmp, int *count)
{
	if (tmp == NULL)
	{
		write(1, "(null)", 6);
		*(count) +=6;
	}
	while (tmp != NULL && *tmp != '\0')
	{
		write(1, tmp, 1);
		*(count) += 1;
		tmp++;
	}
}

void	ft_address(char *tmp, int *count)
{
	write(1, "0x", 2);
	*(count) += 2;
	ft_putnbr((unsigned long long)tmp, HEX, 0, count);
}
