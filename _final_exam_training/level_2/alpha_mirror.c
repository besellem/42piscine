/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:51:16 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 14:04:21 by besellem         ###   ########.fr       */
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
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				ft_putchar(155 - av[1][i]);
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				ft_putchar(219 - av[1][i]);
			else
				ft_putchar(av[1][i]);
		}
	}
	write(1, "\n", 1);
	return (0);
}
