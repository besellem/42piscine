/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:21:34 by besellem          #+#    #+#             */
/*   Updated: 2020/08/04 13:31:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;
	int		i;

	n = (long)(nb);
	if (nb < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	i = 1;
	while (n / i >= 10)
		i *= 10;
	while (i >= 1)
	{
		ft_putchar(n / i % 10 + 48);
		i /= 10;
	}
}
