/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:23:19 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/18 11:23:20 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_memory(unsigned char memory[])
{
	int				i;
	int				line_len;
	unsigned int	line_count;

	line_len = 64;
	line_count = 0;
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % line_len == 0)
			ft_printf("0x%04x : ", line_len * line_count++);
		ft_printf("%02x ", memory[i]);
		if ((i + 1) % line_len == 0)
			ft_putchar('\n');
	}
	exit(0);
}
