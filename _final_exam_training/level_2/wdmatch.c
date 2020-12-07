/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:48:34 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 17:59:37 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		main(int ac, char **av)
{
	int i;
	int j;

	if (ac == 3)
	{
		j = 0;
		i = -1;
		while (av[2][++i])
			if (av[2][i] == av[1][j])
				++j;
		if (j == ft_strlen(av[1]))
			ft_putstr(av[1]);
	}
	ft_putstr("\n");
	return (0);
}
