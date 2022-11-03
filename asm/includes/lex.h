/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:33:03 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/03 16:41:54 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

void	init_token(t_token *t);
void	panic_lex(const char *msg, size_t row, size_t col);
void	lex_tokenization(t_src *s, t_token *t);
void	lex_endof(t_src *s, t_token *t);
void	lex_comment(t_src *s, t_token *t);
void	lex_header(t_src *s, t_token *t);
void	lex_command(t_src *s, t_token *t);

bool	is_label_chars(int c);
bool	is_label(t_src *s);
bool	is_register(t_src *s);

#endif
