/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_st_sti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:01:44 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 13:01:46 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

#define RIGHTMOST_TWO_BYTES 0xFFFF0000

void	print_st(t_car *car, unsigned int args[])
{
	ft_printf("P%5d | ", car->index);
	ft_printf("st r%hhd %hd\n", args[0], args[1]);
}

void	print_sti(t_car *car, unsigned int args[])
{
	int		sum;
	short	target_adr;

	sum = args[1] + args[2];
	target_adr = (car->pc + ((short)sum % IDX_MOD));
	ft_printf("P%5d | ", car->index);
	ft_printf("sti r%hhd %hd %hd\n", args[0], args[1], args[2]);
	ft_printf("%7c| -> store to %hd + %hd = %hd (with pc and mod %hd)\n",
		' ', args[1], args[2], sum, target_adr);
}
