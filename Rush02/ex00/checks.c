/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:26:19 by besellem          #+#    #+#             */
/*   Updated: 2020/08/23 13:26:20 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_is_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY) == -1))
		return (0);
	close(fd);
	return (1);
}

int		ft_check_args(int ac, char **av, t_args *args)
{
	int arg;

	if (ac == 2)
	{
		arg = 1;
		if (!ft_is_file("numbers.dict"))
			return (0);
		args->file = "numbers.dict";
	}
	else if (ac == 3 && !ft_is_file(av[1]))
		return (0);
	else
	{
		arg = 2;
		args->file = av[1];
	}
	if ((args->values = ft_get_values(av[arg])) == NULL)
		return (0);
	return (1);
}

int		ft_file_size(char *file)
{
	char	buf[BUFFER];
	int		size;
	int		fd;
	int		r;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	size = 0;
	while ((r = read(fd, buf, BUFFER)))
		size += r;
	close(fd);
	return (size);
}

t_data	*ft_parse_file(t_args *args)
{
	t_data	*data;
	char	*buf;
	int		file_size;
	int		fd;
	int		i;

	if ((fd = open(args->file, O_RDONLY)) == -1)
		return (NULL);
	if ((file_size = ft_file_size(args->file)) == -1)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (file_size + 1))))
		return (NULL);
	while ((i = read(fd, buf, file_size)))
		buf[i] = '\0';
	close(fd);
	data = NULL;
	data = ft_fill_list(buf);
	free(buf);
	return (data);
}
