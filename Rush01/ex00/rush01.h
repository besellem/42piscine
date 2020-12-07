/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:30:53 by besellem          #+#    #+#             */
/*   Updated: 2020/08/16 11:30:54 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

int		end_test_vertical(int map[4][4], int views_up_down[4], int dir);
int		end_test_horizontal(int map[4][4], int views_left_right[4], int dir);
int		check_duplicates(int map[4][4]);
void	update_map(int map[4][4], int current_columns[4],
		int possible_columns[24][4]);
int		plus_one(int map[4][4], int current_columns[4],
		int possible_columns[24][4]);

#endif
