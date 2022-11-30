/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:02:35 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/30 15:22:42 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	nbr_len(const char *src)
{
	size_t		len;
	const char	*p;

	p = src;
	len = 0;
	if (*p == '-')
	{
		len++;
		p++;
	}
	while (ft_isdigit(*p))
	{
		len++;
		p++;
	}
	return (len);
}

int	validate_arg(t_statement *s, int arg)
{
	return (s->op.args[s->cur_arg] == (s->op.args[s->cur_arg] | arg));
}

void	calc_arg_size(t_sh *d, t_statement *stmt, const char c)
{
	if (c == DIRECT_CHAR)
	{
		stmt->is_dir = true;
		d->byte += stmt->op.size;
	}
	else
		d->byte += IND_SIZE;
}

void	panic_invalidarg(const char *msg, t_src *s, t_statement *stmt)
{
	if (msg)
		ft_dprintf(2, "Invalid parameter %d type %s at [%zu:%zu] "
			"for instruction %s\n", stmt->cur_arg + 1, msg,
			s->row + 1, s->col + 1, stmt->op.name);
	else
		ft_dprintf(2, "Invalid parameter count at [%zu:%zu] for "
			"instruction %s\n", s->row + 1, s->col + 1, stmt->op.name);
	exit(EXIT_FAILURE);
}

void	panic_lex(const char *msg, t_token *t, size_t row, size_t col)
{
	if (!msg)
		ft_dprintf(2, "Lexical error at [%zu:%zu]\n", row + 1, col + 1);
	else if (ft_strequ(msg, "name") || ft_strequ(msg, "comment"))
		ft_dprintf(2, "Champion %s too long (Max length %zu)\n", msg, row);
	else if (t)
		ft_dprintf(2, "Syntax error at token [%zu:%zu] ??? \"%s\"\n",
			row + 1, col + 1, t->content.data);
	else
		ft_dprintf(2, "Syntax error - Unexpected end of input.\n"); //
	exit(EXIT_FAILURE);
}
