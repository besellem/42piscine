/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:29:14 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 15:48:50 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

	if (ac == 2)
	{
		j = 0;
		i = -1;
		while (av[1][++i])
		{
			if ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i + 1] &&
				(av[1][i + 1] != ' ' && av[1][i + 1] != '\t'))
				j = i;
		}
		while (av[1][++j] && av[1][j] != ' ' && av[1][j] != '\t')
			write(1, &av[1][j], 1);
	}
	write(1, "\n", 1);
	return (0);
}
