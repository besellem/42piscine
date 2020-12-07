/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:21:33 by besellem          #+#    #+#             */
/*   Updated: 2020/08/04 14:18:34 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int nb;

	nb = -1;
	while (++nb < 1000)
	{
		if ((nb / 100 % 10) < (nb / 10 % 10) && (nb / 10 % 10) < (nb % 10))
		{
			ft_putchar(nb / 100 % 10 + 48);
			ft_putchar(nb / 10 % 10 + 48);
			ft_putchar(nb % 10 + 48);
			if (nb < 789)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
