/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:27:14 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 11:35:37 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		i = -1;
		while (av[1][++i])
		{
			if ((av[1][i] >= 'A' && av[1][i] <= 'M') ||
				(av[1][i] >= 'a' && av[1][i] <= 'm'))
				ft_putchar(av[1][i] + 13);
			else if ((av[1][i] > 'M' && av[1][i] <= 'Z') ||
					(av[1][i] > 'm' && av[1][i] <= 'z'))
				ft_putchar(av[1][i] - 13);
			else
				ft_putchar(av[1][i]);
		}
	}
	write(1, "\n", 1);
	return (0);
}
