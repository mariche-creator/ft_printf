#include "ft_printf.h"
#include <stdio.h>
#define DEC 10
#define HEX 16
#define BASE_DEC "0123456789"
#define BASE_HEX "0123456789abcdef"
#define BASE_HEX_U "0123456789ABCDEF"

void ft_putnbr(unsigned long long n, unsigned int base, short up, int *count);

int ft_printf(const char *s, ...)
{
    va_list list;
    int i;
    int count;
    char *tmp;
    long long temp;

    i = 0;
    count = 0;
    va_start(list, s);
    while (s[i] != '\0') 
    {
        if (s[i] == '%')
        {
            i++;
            if (s[i] == '%')
            {    
                write(1, "%", 1);
                count++;
            }    
            if (s[i] == 'c')
            {
                temp = va_arg(list, int);
                write(1, &temp, 1);
                count++;
            }
            if (s[i] == 's')
            {
                tmp = va_arg(list, char *);
                while (*tmp != '\0')
                {
                    write(1, tmp, 1);
                    count++;
                    tmp++;
                }
            }
            if (s[i] == 'p')
            {
                tmp = va_arg(list, void *);
                write(1, "0x", 2);
                count += 2;
                ft_putnbr((unsigned long long)tmp, HEX, 0, &count);
            }
            if (s[i] == 'd' || s[i] == 'i')
            {
                temp = va_arg(list, int);
                if (temp < 0)
                {
                    write(1, "-", 1);
                    count++;
                    temp *=(-1);
                }
                ft_putnbr((unsigned long long)temp, DEC, 0, &count);
            }
            if (s[i] == 'u')
            {
                temp = va_arg(list, unsigned int);
                ft_putnbr((unsigned long long)temp, DEC, 0, &count);
            }
            if (s[i] == 'x')
            {
                temp = va_arg(list, int);
                ft_putnbr((unsigned long long)temp, HEX, 0, &count);
            }
            if (s[i] == 'X')
            {
                temp = va_arg(list, int);
                ft_putnbr((unsigned long long)temp, HEX, 1, &count);
            }
        }
        else   
        {
            write(1, &s[i], 1);
            count++;
        }
        i++;
    }
    va_end(list);
    return (count);
}

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
        else if(base == 16 && up == 1)
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
        if (base == 16)
        {
            write(1, &BASE_HEX[n], 1);
            *(count) += 1;
        }
        else
        {
            write(1, &BASE_DEC[n], 1);
            *(count) += 1;
        }
    }
}
