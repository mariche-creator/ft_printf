/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:40:02 by mchernyu          #+#    #+#             */
/*   Updated: 2021/11/26 17:36:46 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr(unsigned long long n, unsigned int base);

int	ft_printf(const char *s, ...)
{
	va_list	list;
    int		i;
    char	*tmp;
    char	temp;

    i = 0;
    va_start(list, s);
    while (s[i] != '\0') 
    {
        if (s[i] == '%')
        {
            i++;
            if (s[i] == '%')
                write(1, "%", 1);
            if (s[i] == 'c')
            {
                temp = va_arg(list, int);
                write(1, &temp, 1);
            }
            if (s[i] == 's')
            {
                tmp = va_arg(list, char *);
                while (*tmp != '\0')
                {
                    write(1, tmp, 1);
                    tmp++;
                }
            }
            if (s[i] == 'p')
            {
                tmp = va_arg(list, void *);
				write(1, "0x", 2);
                ft_putnbr((unsigned long long)tmp, 16);
            } 
        }
        else   
            write(1, &s[i], 1);
        i++;
    }
    va_end(list);
    return (0);		
}

void ft_putnbr(unsigned long long n, unsigned int base)
{
	char	*base_hex;
	char	*base_dec;

	base_hex = "0123456789abcdef";
	base_dec = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		n *= (-1);
	}
	if (n >= base)
	{
		if (base == 16)
		{
			ft_putnbr(n / base, 16);
			write(1, &base_hex[n % base], 1);
		}
		else
		{
			ft_putnbr(n / base, 10);
			write(1, &base_dec[n % base], 1);
		}
	}
	if (n < base)
	{
		if (base == 16)
			write(1, &base_hex[n], 1);
		if (base == 10)
			write(1, &base_dec[n], 1);
	}
}
