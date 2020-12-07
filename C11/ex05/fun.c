/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:56:44 by besellem          #+#    #+#             */
/*   Updated: 2020/08/20 17:56:46 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_atoi(char *str)
{
	int	nb;
	int	min;

	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		++str;
	min = 0;
	while (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			++min;
	nb = 0;
	while (*str && *str >= '0' && *str <= '9')
		nb = nb * 10 + *str++ - 48;
	return (min % 2 == 0 ? nb : -nb);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	long n;
	long tmp;

	n = (long)nb;
	if (n < 0 && (n = -n))
		write(1, "-", 1);
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	tmp = n % 10 + 48;
	write(1, &tmp, 1);
}

void	ft_putnbr_del(int n)
{
	ft_putnbr(n);
	write(1, "\n", 1);
}
