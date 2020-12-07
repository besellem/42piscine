/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 08:53:18 by besellem          #+#    #+#             */
/*   Updated: 2020/08/26 11:54:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		*ft_get_values(char *arg)
{
	int *tab;
	int i;
	int j;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * MAX_TAB)))
		return (NULL);
	while (arg[i] == '0')
		++i;
	j = -1;
	while (++j < (MAX_TAB - ft_strlen(arg + i)))
		tab[j] = 0;
	while (arg[i])
	{
		if (i + 1 == MAX_TAB + 1)
			return (NULL);
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (NULL);
		tab[j++] = arg[i] - 48;
		++i;
	}
	return (tab);
}

void	ft_solve(int *values, t_data *data)
{
	int i;

	i = -1;
	while (++i < MAX_TAB)
	{
		if (values[i] == 0)
			continue ;
		print_third(values[i], i, data);
	}
}

int		main(int ac, char **av)
{
	t_args	args;
	t_data	*data;

	if (ac > 1 && ac < 4)
	{
		if (!ft_check_args(ac, av, &args))
		{
			ft_putstr("Error\n");
			return (0);
		}
		if ((data = ft_parse_file(&args)) == NULL)
		{
			ft_putstr("Dict Error\n");
			return (0);
		}
		ft_print_list(data);
		//	ft_solve(args.values, data);
	}
	return (0);
}
