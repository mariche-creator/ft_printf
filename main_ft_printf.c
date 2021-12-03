/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:21:44 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/03 16:01:37 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    char *str = "STRING";
    char *str1 = "string";
    int count[] = {1, 2, 3, 4};
    char l = 'a';
    char m = 'b';
    char n = 'c';
    int d = 7;
    int i = 8;
    unsigned int a = 4294967295;
    int temp = 0;
    int b = 500;
    int c = -1;
	char *s = NULL;
    temp = ft_printf("My character, %%, string: %c, %c, %%%%, %c, %s\n", l, m, n, str1);
    printf("My return: %d\n", temp);
    temp = printf("Or character, %%, string: %c, %c, %%%%, %c, %s\n", l, m, n, str1);
    printf("Or return: %d\n", temp);
    temp = ft_printf("My two strings with good: HELLO*%s*GOOD, %s\n", str, str1);
    printf("My return: %d\n", temp);
    temp = printf("Or two strings with good: HELLO*%s*GOOD, %s\n", str, str1); 
    printf("Or return: %d\n", temp);
    temp = ft_printf("My int array: %p\n", count);
    printf("My return: %d\n", temp);
    temp = printf("Or int array: %p\n", count);
    printf("Or return: %d\n", temp);
    temp = ft_printf("My int and dec: %d, %i\n", d, i);
    printf("My return: %d\n", temp);
    temp = printf("Or int and dec: %d, %i\n", d, i);
    printf("Or return: %d\n", temp);
    temp = ft_printf("My unsigned dec: %u\n", a);
    printf("My return: %d\n", temp);
    temp = printf("Or unsigned dec: %u\n", a);
    printf("Or return: %d\n", temp);
    temp = ft_printf("My hex lowercase: %x\n", b);
    printf("My return: %d\n", temp);
    temp = printf("Or hex lowercase: %x\n", b);
    printf("Or return: %d\n", temp);
    temp = ft_printf("My hex uppercase: %X\n", c);
    printf ("Or return: %d\n", temp);
    temp = printf("Or hex uppercase: %X\n", c);
    printf("Or return: %d\n", temp);
    temp = ft_printf("My null string: %s\n", s);
	printf("My return: %d\n", temp);
	temp = printf("Or null string: %s\n", s);
	printf("My return: %d\n", temp);
    return (0);
}

