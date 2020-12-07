/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:14:38 by besellem          #+#    #+#             */
/*   Updated: 2020/08/26 13:11:54 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int len;

	len = 0;
	while (dest[len])
		++len;
	i = -1;
	while (src[++i])
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*cpy;
	int		i;

	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		cpy[i] = str[i];
	cpy[i] = '\0';
	return (cpy);
}

t_tab	*ft_file_size_stdin(int offset)
{
	t_tab	*tab;
	char	*buffer;
	int		r;
	int		count;
	int		i;

	if (!(tab = (t_tab *)malloc(sizeof(t_tab) * (1000))))
		return (NULL);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER + 1))))
		return (NULL);
	count = 0;
	i = -1;
	while ((r = read(STDIN_FILENO, buffer, BUFFER)))
	{
		count += r;
		buffer[r] = '\0';
		if (r == BUFFER && count > offset && BUFFER < offset)
			continue ;
		tab[++i].data = ft_strdup(buffer);
		tab[i].size = r;
	}
	tab[i + 1].data = NULL;
	free(buffer);
	return (tab);
}

void	ft_free_tab(t_tab *tab)
{
	int i;

	i = -1;
	while (tab[++i].data)
		free(tab[i].data);
	free(tab);
}

void	ft_tail_stdin(int offset)
{
	t_tab	*tab;
	char	*buffer;
	int		file_size;
	int		i;

	tab = ft_file_size_stdin(offset);
	file_size = 0;
	i = -1;
	while (tab[++i].data)
		file_size += tab[i].size;
	if (!(buffer = (char *)malloc(sizeof(char) * (file_size + 1))))
		return ;
	*buffer = '\0';
	i = -1;
	while (tab[++i].data)
		ft_strcat(buffer, tab[i].data);
	if (offset > file_size)
		write(1, buffer, file_size);
	else
		write(1, buffer + (file_size - offset), offset);
	free(buffer);
	ft_free_tab(tab);
}
