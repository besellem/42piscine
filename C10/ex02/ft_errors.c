/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:17:12 by besellem          #+#    #+#             */
/*   Updated: 2020/08/25 23:32:06 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_print_file_name(char *file)
{
	write(1, "==> ", 4);
	write(1, file, ft_strlen(file));
	write(1, " <==\n", 5);
}

int		ft_is_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY) == -1))
		return (0);
	close(fd);
	return (1);
}

int		ft_print_error(int ac, char **av, int i)
{
	int count;
	int tmp;

	if (ft_is_file(av[i]))
		return (0);
	ft_putstr_fd(basename(av[0]), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(av[i], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	tmp = 0;
	count = i;
	while (--count > 0)
		if (!ft_is_file(av[count]))
			++tmp;
	if (tmp + 1 == i && ft_is_file(av[i + 1]))
		return (1);
	else if ((ac - i - 1) && ft_is_file(av[i + 1]))
		ft_putstr_fd("\n", 2);
	return (1);
}

void	ft_option_offset(int ac, char **av, int *offset)
{
	if (ac < 2)
		*offset = -1;
	else if (ft_strncmp(av[1], "-c", 2) != 0)
		*offset = -1;
	else if (ft_strlen(av[1]) > 2)
		*offset = ft_atoi(av[1] + 2);
	else if (ac > 2 && ft_str_is_numeric(av[2]))
		*offset = ft_atoi(av[2]);
	else
	{
		ft_putstr_fd(basename(av[0]), 2);
		ft_putstr_fd(": illegal offset -- ", 2);
		ft_putstr_fd(av[2], 2);
		ft_putstr_fd("\n", 2);
		*offset = -1;
	}
	if (offset < 0)
		*offset = -1;
}

void	ft_arg_nbr(int ac, char **av, int *i)
{
	if (ac < 2)
		*i = -1;
	else if (ft_strlen(av[1]) > 2)
		*i = 1;
	else if (ac >= 4 && ft_strlen(av[1]) == 2)
		*i = 2;
	else
		*i = -1;
}
