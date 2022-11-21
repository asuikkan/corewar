/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:07:23 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:07:25 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

#define RIGHTMOST_BYTE 0xFF000000

static void	copy_to_memory(unsigned char memory[], unsigned int adr,
	unsigned int value)
{
	int				byte_count;
	unsigned int	byte;

	byte_count = -1;
	while (++byte_count < REG_SIZE)
	{
		byte = value << BITS_IN_BYTE * byte_count & RIGHTMOST_BYTE;
		byte = byte >> (REG_SIZE - 1) * BITS_IN_BYTE;
		memory[adr % MEM_SIZE] = byte;
		adr++;
	}
}

void	op_st(t_info *info, t_car *car)
{
	unsigned char	arg_types[2];
	unsigned int	args[2];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	if (arg_types[0] != REG_CODE
		|| (arg_types[1] != REG_CODE && arg_types[1] != IND_CODE))
		return ;
	args[0] = get_argument(info, 1, car);
	if (args[0] > REG_NUMBER || !args[0])
		return ;
	args[1] = get_argument(info, 2, car);
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		if (info->verbose_opts & SHOW_OP)
			print_st(car, args);
		car->reg[args[1]] = car->reg[args[0]];
		return ;
	}
	if (info->verbose_opts & SHOW_OP)
		print_st(car, args);
	args[0] = car->reg[args[0]];
	copy_to_memory(info->memory, car->pc + ((short)args[1] % IDX_MOD), args[0]);
}

static int	save_args_sti(t_car *car, unsigned int args[],
	unsigned char arg_types[], unsigned char memory[])
{
	short	adr;

	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return (-1);
		args[1] = car->reg[args[1]];
	}
	else if (arg_types[1] == IND_CODE)
	{
		adr = (car->pc + ((short)args[1] % IDX_MOD)) % MEM_SIZE;
		args[1] = cat_n_bytes(&memory[adr], REG_SIZE, memory);
	}
	if (arg_types[2] == REG_CODE)
	{
		if (args[2] > REG_NUMBER || !args[2])
			return (-1);
		args[2] = car->reg[args[2]];
	}
	return (1);
}

void	op_sti(t_info *info, t_car *car)
{
	unsigned char	arg_types[3];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	arg_types[2] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3);
	if (arg_types[0] != REG_CODE || !arg_types[1]
		|| (arg_types[2] != REG_CODE && arg_types[2] != DIR_CODE))
		return ;
	args[0] = get_argument(info, 1, car);
	if (args[0] > REG_NUMBER || !args[0])
		return ;
	args[1] = get_argument(info, 2, car);
	args[2] = get_argument(info, 3, car);
	if (save_args_sti(car, args, arg_types, info->memory) == -1)
		return ;
	if (info->verbose_opts & SHOW_OP)
		print_sti(car, args);
	args[0] = car->reg[args[0]];
	copy_to_memory(info->memory,
		car->pc + (short)((args[1] + args[2]) % IDX_MOD),
		args[0]);
}
