/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:56:16 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/24 11:38:16 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// u_int16_t ushort_to_bigendian(u_int16_t nbr)
// {
// 	u_int16_t	ret;

// 	ret = (nbr & 0xFF00) >> 8;
// 	ret = (nbr & 0x00FF) << 8 | ret;
// 	return (ret);
// }

u_int32_t uint_to_bigendian(u_int32_t nbr)
{
	u_int32_t	ret;

	ret = (nbr & 0xFF000000) >> 24;
	ret = (nbr & 0x000000FF) << 24 | ret;
	ret = (nbr & 0x00FF0000) >> 8 | ret;
	ret = (nbr & 0x0000FF00) << 8 | ret;
	return (ret);
}

char	*create_filename(char *src)
{
	char *filename;
	char *ret;

	filename = ft_strndup(src, ft_strlen(src) - 1);
	ret = ft_strjoin(filename, "cor");
	ft_strdel(&filename);
	return (ret);
}