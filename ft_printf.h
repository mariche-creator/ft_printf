/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:20:10 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/03 17:21:03 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#define DEC 10
#define HEX 16
#define BASE_DEC "0123456789"
#define BASE_HEX "0123456789abcdef"
#define BASE_HEX_U "0123456789ABCDEF"

int	ft_printf(const char *s, ...);
void	ft_percent(int *count);
void	ft_character(long long *temp, int *count);
void	ft_string(char *tmp, int *count);
void	ft_address(char *tmp, int *count);
void	ft_putnbr(unsigned long long n, unsigned int base, short up, int **count);

#endif
