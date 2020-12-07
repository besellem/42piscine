/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:38:24 by besellem          #+#    #+#             */
/*   Updated: 2020/08/07 12:38:26 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = -1;
	if (!*base)
		return (0);
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i;
		while (--j > 0)
			if (base[j] == base[i] || base[j] == '-' || base[j] == '+')
				return (0);
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long n;

	n = nbr;
	if (ft_check_base(base) < 2)
		return ;
	if (n < 0 && (n = -n))
		write(1, "-", 1);
	if ((n / ft_check_base(base)) > 0)
		ft_putnbr_base(n / ft_check_base(base), base);
	write(1, &base[n % ft_check_base(base)], 1);
}
