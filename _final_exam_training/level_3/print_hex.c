/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:57:17 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 22:02:13 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *str)
{
	int n;
	int min;

	min = 1;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			min = -1;
	n = 0;
	while (*str && *str >= '0' && *str <= '9')
		n = n * 10 + *str++ - 48;
	return (n * min);
}

void	ft_print_hex(int nb)
{
	long	n;
	char	*base;

	base = "0123456789abcdef";
	n = (long)nb;
	if (n < 0 && (n = -n))
		write(1, "-", 1);
	if (n / 16 > 0)
		ft_print_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
