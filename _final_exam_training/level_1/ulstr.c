/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:46:06 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 11:49:27 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	f(char c)
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
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				f(av[1][i] - 32);
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				f(av[1][i] + 32);
			else
				f(av[1][i]);
		}
	}
	f('\n');
	return (0);
}
