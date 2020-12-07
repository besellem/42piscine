/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 22:04:28 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 22:12:00 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_atoi(const char *str)
{
	int n;
	int min;

	min = 1;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			min = -1;
	n = 0;
	while (*str && *str >= '0' && *str <= '9')
		n = n * 10 + *str++ - 48;
	return (n * min);
}

void	ft_putnbr(int nb)
{
	long	n;
	long	tmp;

	n = (long)nb;
	if (n < 0 && (n = -n))
		write(1, "-", 1);
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	tmp = n % 10 + 48;
	write(1, &tmp, 1);
}

int		main(int ac, char **av)
{
	int n;
	int i;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		i = 0;
		while (++i < 10)
		{
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putnbr(n);
			ft_putstr(" = ");
			ft_putnbr(i * n);
			ft_putstr("\n");
		}
	}
	else
		ft_putstr("\n");
	return (0);
}
