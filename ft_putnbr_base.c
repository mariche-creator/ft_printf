/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:30:17 by mchernyu          #+#    #+#             */
/*   Updated: 2021/11/26 16:40:31 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr_base(unsigned long long n)
{
	char	*temp;

	temp = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		n *= (-1);
	}
	if (n >= 16)
	{
		ft_putnbr_base(n / 16);
		write(1, &temp[n % 16], 1);
	}
	if (n < 16)
		write(1, &temp[n], 1);
}
