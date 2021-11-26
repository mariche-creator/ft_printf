/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:21:44 by mchernyu          #+#    #+#             */
/*   Updated: 2021/11/26 10:22:13 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
//    char *str = "STRING";
    char *str1 = "string";
//    char l = 'a';
//    char m = 'b';
//    char n = 'c';
//    ft_printf("%c\n%c\n%%%%\n%c\n%s\n", l, m, n, str1);
//    printf("%c\n%c\n%%%%\n%c\n%s\n", l, m, n, str1);
//    ft_printf("%%\n");
//    ft_printf("HELLO*%s*GOOD, %s\n", str, str1);
    ft_printf("%p\n", str1);
    printf("%p\n", str1);
    return (0);
}

