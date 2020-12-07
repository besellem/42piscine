/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:56:02 by besellem          #+#    #+#             */
/*   Updated: 2020/08/18 14:56:03 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_check(int nb2, char *operand)
{
	int i;

	i = -1;
	while (operand[++i])
	{
		if (i > 0 || (operand[i] != '-' && operand[i] != '+' &&
			operand[i] != '/' && operand[i] != '*' && operand[i] != '%'))
		{
			ft_putnbr_del(0);
			return (1);
		}
	}
	if (operand[0] == '/' && nb2 == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	else if (operand[0] == '%' && nb2 == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int nb1;
	int nb2;

	if (ac == 4)
	{
		nb1 = ft_atoi(av[1]);
		nb2 = ft_atoi(av[3]);
		if (ft_check(nb2, av[2]))
			return (0);
		if (av[2][0] == '+')
			ft_putnbr_del(nb1 + nb2);
		else if (av[2][0] == '-')
			ft_putnbr_del(nb1 - nb2);
		else if (av[2][0] == '/')
			ft_putnbr_del(nb1 / nb2);
		else if (av[2][0] == '*')
			ft_putnbr_del(nb1 * nb2);
		else if (av[2][0] == '%')
			ft_putnbr_del(nb1 % nb2);
	}
	return (0);
}
