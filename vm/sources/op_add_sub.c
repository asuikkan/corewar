/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:02:33 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:02:36 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_add(t_info *info, t_car *car)
{
	unsigned char	args[3];
	unsigned int	sum;

	ft_bzero(args, sizeof(args));
	if (get_crumb(info->memory[(car->pc + 1) & MEM_SIZE], 1) != REG_CODE
		|| get_crumb(info->memory[(car->pc + 1) & MEM_SIZE], 2) != REG_CODE
		|| get_crumb(info->memory[(car->pc + 1) & MEM_SIZE], 3) != REG_CODE)
		return ;
	args[0] = info->memory[(car->pc + 2) & MEM_SIZE];
	args[1] = info->memory[(car->pc + 3) & MEM_SIZE];
	args[2] = info->memory[(car->pc + 4) & MEM_SIZE];
	if ((args[0] > REG_NUMBER || !args[0])
		|| (args[1] > REG_NUMBER || !args[1])
		|| (args[2] > REG_NUMBER || !args[2]))
		return ;
	sum = car->reg[args[0]] + car->reg[args[1]];
	car->reg[args[2]] = sum;
	car->carry = 1;
}

void	op_sub(t_info *info, t_car *car)
{
	(void)info;
	(void)car;
}
