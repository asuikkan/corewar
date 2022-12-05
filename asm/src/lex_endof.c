/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_endof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:21:04 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/30 15:25:56 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	validate_eol(t_src *s, t_statement *stmt)
{
	if (stmt->sep != stmt->op.argc - 1 || stmt->cur_arg != stmt->op.argc)
		panic_invalidarg(NULL, s, stmt);
	stmt->is_valid = true;
}

void	lex_endof(t_sh *d, t_src *s, t_token *t)
{
	t_statement	*stmt;

	stmt = ft_vecget(&d->code, d->code.len - 1);
	if (*(char *)&s->buf.data[s->index] == '\n')
	{
		if (stmt && stmt->is_valid == false)
			validate_eol(s, stmt);
		t->symbol = la_eol;
		*(char *)&t->content.data[0] = '\n';
		s->row++;
		s->col = 0;
		s->index++;
	}
	if (*(char *)&s->buf.data[s->index] == '\0')
	{
		if (stmt && stmt->is_valid == false)
			panic_lex("Unexpected end", NULL, s->row, s->col);
		t->symbol = la_eof;
		*(char *)&t->content.data[0] = '\0';
	}
}