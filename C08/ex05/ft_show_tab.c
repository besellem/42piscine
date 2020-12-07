/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:25:47 by besellem          #+#    #+#             */
/*   Updated: 2020/08/12 20:25:48 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putendl(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	long n;
	long tmp;

	n = (long)nb;
	if (n < 0 && (n = -n))
		write(1, "-", 1);
	if (n >= 10)
		ft_putnbr(n / 10);
	tmp = n % 10 + 48;
	write(1, &tmp, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = -1;
	while (par[++i].str)
	{
		ft_putendl(par[i].str);
		ft_putnbr(par[i].size);
		ft_putendl("");
		ft_putendl(par[i].copy);
	}
}
