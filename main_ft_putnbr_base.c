/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putnbr_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:47:07 by mchernyu          #+#    #+#             */
/*   Updated: 2021/11/26 16:17:18 by mchernyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putnbr_base(unsigned long long n, unsigned long long base);

int main(void)
{
	unsigned long long  n = 255;
	int base = 16;

	ft_putnbr_base(n, base);
}
