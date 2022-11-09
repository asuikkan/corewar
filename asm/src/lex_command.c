/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:29:33 by altikka           #+#    #+#             */
/*   Updated: 2022/11/09 17:31:48 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void create_statement(t_sh *d, char *key)
{
	t_statement	temp;

	temp.op = g_optab[hash_get(&d->ops, key) - 1];
	temp.loc = d->byte;
	d->byte += 1 + g_optab[temp.op.op_code - 1].acb;
	temp.cur_arg = 0;
	if(ft_vecpush(&d->code, &temp) < 0)
		panic("Malloc error with exec code.");
}

static void	lex_operation(t_sh *d, t_src *s, t_token *t)
{
	char	*p;
	size_t	ofs;

	t->symbol = la_op;
	p = (char *)&s->buf.data[s->index];
	while (is_label_chars(*p))
		p++;
	ofs = p - (char *)&s->buf.data[s->index];
	ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
	ft_vecpush(&t->content, "\0");
	if (!hash_lookup(&d->ops, (char *)t->content.data))
		panic_lex("...", 0, 0); //?
	create_statement(d,(char *)t->content.data);
	s->index += ofs;
	s->col += ofs;
}

void	lex_command(t_sh *d, t_src *s, t_token *t)
{
	char	*p;
	size_t	ofs;

	if (is_label(s))
	{
		t->symbol = la_label;
		t->is_label = true;
		//add to hashmap
		p = ft_strchr(&s->buf.data[s->index], LABEL_CHAR);
		ofs = p - (char *)&s->buf.data[s->index] + 1;
		ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
		s->index += ofs;
		s->col += ofs;
	}
	else
		lex_operation(d, s, t);
}
