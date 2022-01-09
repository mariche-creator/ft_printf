/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:20:10 by mchernyu          #+#    #+#             */
/*   Updated: 2021/12/06 18:47:51 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# define DEC 10
# define HEX 16
# define BASE_DEC "0123456789"
# define BASE_HEX "0123456789abcdef"
# define BASE_HEX_U "0123456789ABCDEF"

typedef struct var_holder
{
	int			count;
	char		*tmp;
	long long	temp;
}	t_var;

int		ft_printf(const char *s, ...);
void	ft_percent(int *count);
void	ft_character(long long *temp, int *count, va_list *list);
void	ft_string(char *tmp, int *count, va_list *list);
void	ft_address(char *tmp, int *count, va_list *list);
void	ft_putn(unsigned long long n, unsigned int base, short up, int *count);
void	m_b(unsigned long long *n, unsigned int base, short up, int **count);
void	l_b(unsigned long long *n, unsigned int base, short up, int **count);
void	ft_put_minus(int *count, long long *temp);
void	f(const char **s, va_list *list, t_var *var);
void	ft_decimal(long long *temp, int *count, va_list *list);
void	ft_u_decimal(long long *temp, int *count, va_list *list);
void	ft_hex_low(long long *temp, int *count, va_list *list);
void	ft_hex_up(long long *temp, int *count, va_list *list);

#endif
