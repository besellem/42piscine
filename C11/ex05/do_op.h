/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:56:58 by besellem          #+#    #+#             */
/*   Updated: 2020/08/20 17:57:02 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

/*
** FUN.C
*/
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putnbr_del(int n);

/*
** MAIN.C
*/
int		ft_check(int nb2, char *operand);

#endif
