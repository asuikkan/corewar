/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:25:19 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/27 13:25:21 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_empty_slot(t_champion *ch_list[])
{
	int	i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (ch_list[i] == NULL)
			break ;
	}
	return (i);
}

static void	organize_players(t_champion *ch_list[], int index, int *taken_ids)
{
	int	j;
	int	target;

	if (!ch_list[index])
		return ;
	target = MAX_PLAYERS - 1;
	j = MAX_PLAYERS;
	while (--j >= index)
	{
		if (!taken_ids[j])
		{
			if (target != j)
				ft_memcpy(ch_list[target], ch_list[j], sizeof(t_champion));
			target = j;
		}
	}
}

int	set_player_id(int *id, t_champion *ch_list[])
{
	static int	taken_ids[MAX_PLAYERS];
	int			player_index;

	if (*id > 0)
	{
		player_index = *id - 1;
		if (taken_ids[player_index])
			error_handler(DUPLICATE_PLAYER_ID);
		organize_players(ch_list, player_index, taken_ids);
		taken_ids[player_index] = 1;
		*id = 0;
	}
	else
		player_index = get_empty_slot(ch_list);
	return (player_index);
}
