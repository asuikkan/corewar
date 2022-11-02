/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:15:25 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/02 18:08:56 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	reset_token(t_token *t)
{
	t->symbol = la_unknown;
	t->content.len = 0;
	t->declared = false;
	t->is_label = false;
}

static void	debug_lex(t_token *t)
{
	char	*symbols[15] = {"la_unknown", "la_eof", "la_eol", "la_label",
		"la_op", "la_comm", "la_champname", "la_champcomm", "la_reg",
		"la_dir", "la_ind", "la_num", "la_comma", "la_minus", "la_plus"};

	ft_printf("%2d: token "YELLOW"%s"EOC": ", t->num, symbols[t->symbol]);
	write(1, t->content.data, t->content.len);
	ft_printf("\n");
}

int	lex(t_sh *d, t_src *s)
{
	t_token	t;
	size_t	count;

	(void)d;

	count = 1;
	init_token(&t);
	while (t.symbol != la_eof)
	{
		source_next(s);
		lex_tokenization(s, &t);
		t.num = (int ) count++; //
		if (t.symbol == la_eof)
			exit(1);
		debug_lex(&t);
		reset_token(&t);
	}
	return (1);
}