/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:54:43 by besellem          #+#    #+#             */
/*   Updated: 2020/08/27 17:17:22 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		div;
	char	tmp;

	div = 128;
	while (div > 0)
	{
		tmp = ((octet / div) % 2 == 0) ? 0 + 48 : 1 + 48;
		write(1, &tmp, 1);
		div /= 2;
	}
}
