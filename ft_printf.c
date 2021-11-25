#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    va_list list;
    int i;
    char *tmp;
    char temp;

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
                write(1, &tmp, 16);
            } 
        }
        else   
            write(1, &s[i], 1);
        i++;
    }
    va_end(list);
    return (0);
}
