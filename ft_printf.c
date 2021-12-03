/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:20:59 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/03 17:53:13 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void ft_putnbr(unsigned long long n, unsigned int base, short up, int *count);

int ft_printf(const char *s, ...)
{
    va_list list;
    int count;
    char *tmp;
    long long temp;

    count = 0;
    va_start(list, s);
    while (*s != '\0') 
    {
        if (*s == '%')
        {
            s++;
            if (*s == '%')
				ft_percent(&count);		
            if (*s == 'c')
            {
                temp = va_arg(list, int);
                ft_character(&temp, &count);
            }
            if (*s == 's')
            {
                tmp = va_arg(list, char *);
				ft_string(tmp, &count);
            }
            if (*s == 'p')
            {
                tmp = va_arg(list, void *);
				ft_address(tmp, &count);
                /*write(1, "0x", 2);
                count += 2;
                ft_putnbr((unsigned long long)tmp, HEX, 0, &count);*/
            }
            if (*s == 'd' || *s == 'i')
            {
                temp = va_arg(list, int);
                if (temp < 0)
                {
                    write(1, "-", 1);
                    count++;
                    temp *=(-1);
                }
                ft_putnbr((unsigned long long)temp, DEC, 0, *count);
            }
            if (*s == 'u')
            {
                temp = va_arg(list, unsigned int);
                ft_putnbr((unsigned long long)temp, DEC, 0, *count);
            }
            if (*s == 'x')
            {
                temp = va_arg(list, unsigned int);
                if (temp < 0)
                {
                    write(1, "-", 1);
                    count++;
                    temp *=(-1);
                }
                ft_putnbr((unsigned long long)temp, HEX, 0, *count);
            }
            if (*s == 'X')
            {
                temp = va_arg(list, unsigned int);
				if (temp < 0)
                {
                    write(1, "-", 1);
                    count++;
                    temp *=(-1);
                }
                ft_putnbr((unsigned long long)temp, HEX, 1, *count);
            }
        }
        else   
        {
            write(1, s, 1);
            count++;
        }
        s++;
    }
    va_end(list);
    return (count);
}

/*void    ft_putnbr(unsigned long long n, unsigned int base, short up, int *count)
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
}*/
