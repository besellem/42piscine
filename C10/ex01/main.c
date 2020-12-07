/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:58:40 by besellem          #+#    #+#             */
/*   Updated: 2020/08/18 18:58:41 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <libgen.h>
#include <string.h>

#define BUFFER 4096

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_print_error(char *exec_name, char *file, int err)
{
	ft_putstr_fd(basename(exec_name), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(err), 2);
	ft_putstr_fd("\n", 2);
}

void	ft_cat_stdin(void)
{
	char	buf[BUFFER];
	int		r;

	while ((r = read(STDIN_FILENO, buf, BUFFER)))
	{
		buf[r] = '\0';
		write(1, buf, r);
	}
}

void	ft_cat(char *exec_name, char *file)
{
	char	buf[BUFFER];
	int		fd;
	int		r;

	if ((fd = open(file, O_RDWR)) == -1)
	{
		ft_print_error(exec_name, file, errno);
		return ;
	}
	while ((r = read(fd, buf, BUFFER)))
	{
		buf[r] = '\0';
		write(1, buf, r);
	}
	close(fd);
}

int		main(int ac, char **av)
{
	int i;

	if (ac == 1)
		ft_cat_stdin();
	else if (ac > 1)
	{
		i = 0;
		while (++i < ac)
			ft_cat(av[0], av[i]);
	}
	return (0);
}
