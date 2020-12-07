/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 18:00:36 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 18:13:10 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_prime(int n)
{
	int i;

	i = 1;
	while (++i < n)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int nb;
	int min;

	min = 1;
	nb = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		++str;
	if (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			min = -1;
	while (*str && (*str >= '0' && *str <= '9'))
		nb = (nb * 10) + (*str++ - 48);
	return (nb * min);
}

void	ft_putnbr(int nb)
{
	long n;
	long tmp;

	n = (long)nb;
	if (n < 0 && (n = -n))
		write(1, "-", 1);
	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	tmp = n % 10 + 48;
	write(1, &tmp, 1);
}

int		main(int ac, char **av)
{
	int i;
	int nb;
	int sum;

	sum = 0;
	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		if (nb > 0)
		{
			i = 1;
			while (++i <= nb)
				if (ft_is_prime(i))
					sum += i;
		}
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
