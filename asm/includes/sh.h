/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:49:05 by altikka           #+#    #+#             */
/*   Updated: 2022/11/28 16:04:05 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

typedef struct s_statement
{
	t_op		op;
	u_int8_t	acb;			//
	long		args[3];
	u_int8_t	arg_type[3];
	int			cur_arg;
	int			sep;
	bool		is_dir;
	u_int32_t	loc;
}				t_statement;

typedef struct s_sh
{
	t_header	header;
	t_vec		code;
	t_hashmap	ops;
	char		*filename;
	u_int32_t	byte;
}				t_sh;

#endif
