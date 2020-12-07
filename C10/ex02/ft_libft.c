/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:18:06 by besellem          #+#    #+#             */
/*   Updated: 2020/08/25 21:13:26 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		ft_atoi(char *str)
{
	int nb;
	int min;

	min = 0;
	nb = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		++str;
	while (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			++min;
	while (*str && (*str >= '0' && *str <= '9'))
		nb = (nb * 10) + (*str++ - 48);
	return ((min % 2 == 0) ? nb : -nb);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
		++i;
	return (s1[i] - s2[i]);
}

int		ft_str_is_numeric(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}
