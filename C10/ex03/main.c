/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:05:09 by besellem          #+#    #+#             */
/*   Updated: 2020/08/24 15:05:10 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int		ft_check_args(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && ft_strncmp(av[1], "-C", 2) == 0))
		return (2);
	else if (ac > 2 && ft_strncmp(av[1], "-C", 2) != 0)
		return (-1);
	return (-1);
}

int		main(int ac, char **av)
{
	ft_check_args(ac, av);
	return (0);
}
