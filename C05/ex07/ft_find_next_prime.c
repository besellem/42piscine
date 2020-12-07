/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 11:06:47 by besellem          #+#    #+#             */
/*   Updated: 2020/08/11 11:06:49 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int f;

	if (nb < 2)
		return (0);
	f = 1;
	while (++f <= 46341 && f < nb)
	{
		if (nb % f == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int f;

	if (ft_is_prime(nb))
		return (nb);
	f = nb + 1;
	while (!ft_is_prime(f))
		++f;
	return (f);
}
