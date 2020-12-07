/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:50:35 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 21:55:27 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_pgcd(int a, int b)
{
	return ((a % b == 0) ? b : ft_pgcd(b, a % b));
}

int		main(int ac, char **av)
{
	int a;
	int b;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);

		if (a <= 0 || b <= 0)
		{
			printf("\n");
			return (0);
		}
		printf("%d", ft_pgcd(a, b));
	}
	printf("\n");
	return (0);
}
