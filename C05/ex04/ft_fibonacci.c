/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:07:33 by besellem          #+#    #+#             */
/*   Updated: 2020/08/11 09:07:35 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci_rec(int index, int index1, int index2)
{
	if (index == 0)
		return (index2);
	return (ft_fibonacci_rec(index - 1, index2, index1 + index2));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	return (ft_fibonacci_rec(index - 1, 0, 1));
}
