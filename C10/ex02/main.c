/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 20:02:21 by besellem          #+#    #+#             */
/*   Updated: 2020/08/25 21:34:04 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_file_size(char *file)
{
	char	buf[BUFFER];
	int		size;
	int		fd;
	int		r;

	if ((fd = open(file, O_RDWR)) == -1)
		return (-1);
	size = 0;
	while ((r = read(fd, buf, BUFFER)))
		size += r;
	close(fd);
	return (size);
}

void	ft_tail(char *file, int offset, int mult_files)
{
	char	*buffer;
	int		file_size;
	int		fd;
	int		r;

	if (mult_files)
		ft_print_file_name(file);
	if ((fd = open(file, O_RDWR)) == -1)
		return ;
	file_size = ft_file_size(file);
	if (!(buffer = (char *)malloc(sizeof(char) * (file_size + 1))))
		return ;
	while ((r = read(fd, buffer, file_size)))
		buffer[r] = '\0';
	if (offset > file_size)
		write(1, buffer, file_size);
	else
		write(1, buffer + (file_size - offset), offset);
	free(buffer);
	close(fd);
}

int		main(int ac, char **av)
{
	int offset;
	int mult_files;
	int i;

	ft_option_offset(ac, av, &offset);
	ft_arg_nbr(ac, av, &i);
	if (ac > 2 && i != -1)
	{
		if (offset == -1)
			return (0);
		mult_files = (i + 1 == ac - 1) ? 0 : 1;
		while (++i < ac)
		{
			if (ft_print_error(ac, av, i))
				continue ;
			ft_tail(av[i], offset, mult_files);
			if (mult_files && (i + 1) < ac && ft_is_file(av[i + 1]))
				write(1, "\n", 1);
		}
	}
	else if (offset > 0)
		ft_tail_stdin(offset);
	return (0);
}
