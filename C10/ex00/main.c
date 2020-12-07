/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:34:45 by besellem          #+#    #+#             */
/*   Updated: 2020/08/18 18:34:47 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER 4096

void	ft_putendl_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
	write(fd, "\n", 1);
}

void	ft_display_file(char *file)
{
	char	buf[BUFFER];
	int		fd;
	int		r;

	if ((fd = open(file, O_RDWR)) == -1)
	{
		ft_putendl_fd("Cannot read file.", 2);
		return ;
	}
	while ((r = read(fd, buf, BUFFER)))
	{
		buf[r + 1] = '\0';
		write(1, buf, r);
	}
	close(fd);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_display_file(av[1]);
	else if (ac == 1)
		ft_putendl_fd("File name missing.", 2);
	else
		ft_putendl_fd("Too many arguments.", 2);
	return (0);
}
