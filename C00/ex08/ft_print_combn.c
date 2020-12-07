/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:17:17 by besellem          #+#    #+#             */
/*   Updated: 2020/08/05 19:18:54 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int i;
	int tmp;

	i = 1;
	while (nb / i >= 10)
		i *= 10;
	while (i > 0)
	{
		tmp = (nb / i % 10) + 48;
		write(1, &tmp, 1);
		i /= 10;
	}
}

/*
** FT_CHECK:
** mode == 0 -> RETURN 10^n
** mode == 1 -> RETURN LENGTH OF n
*/

int		ft_check(int n, int mode)
{
	int i;
	int j;

	i = 1;
	if (mode == 0)
	{
		j = -1;
		while (++j < n)
			i *= 10;
		return (i);
	}
	else if (mode == 1)
	{
		j = 1;
		while (n / (i *= 10) > 0)
			++j;
		return (j);
	}
	return (1);
}

int		ft_print_zero(int nbr, int n)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (nbr / (j *= 10) > 0)
		++i;
	if (n - i > 1)
		return (0);
	while (i < n--)
		write(1, "0", 1);
	return (1);
}

int		ft_print_res(int nb, int n)
{
	int i;
	int max;

	ft_putnbr(nb);
	if (ft_check(nb, 1) == ft_check(ft_check(n, 0), 1) - 1)
	{
		i = 10 - ft_check(nb, 1);
		max = 0;
		while (i < 10)
		{
			max = (max * 10) + i;
			++i;
		}
		if (nb == max)
			return (1);
	}
	write(1, ", ", 2);
	return (0);
}

void	ft_print_combn(int n)
{
	int i;
	int j;
	int count;
	int max;

	i = -1;
	max = ft_check(n, 0);
	while (++i < max && n > 0 && n < 10)
	{
		if (i == 0 && n == 1)
		{
			write(1, "0, ", 3);
			continue ;
		}
		j = 1;
		count = 0;
		while ((i / j) % 10 > (i / j / 10) % 10 && (j *= 10) != 0)
			++count;
		if (count == ft_check(i, 1) && ft_print_zero(i, n))
			if (ft_print_res(i, n))
				return ;
	}
}
