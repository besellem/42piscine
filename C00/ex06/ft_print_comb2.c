/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:11:42 by besellem          #+#    #+#             */
/*   Updated: 2020/08/04 14:15:26 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int n1, int n2)
{
	ft_putchar(n1 / 10 % 10 + 48);
	ft_putchar(n1 % 10 + 48);
	ft_putchar(' ');
	ft_putchar(n2 / 10 % 10 + 48);
	ft_putchar(n2 % 10 + 48);
	if (n1 < 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int nb1;
	int nb2;

	nb1 = -1;
	while (++nb1 < 100)
	{
		nb2 = nb1;
		while (++nb2 < 100)
			ft_print(nb1, nb2);
	}
}
