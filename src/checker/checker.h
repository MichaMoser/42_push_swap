/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 13:32:44 by mmoser        #+#    #+#                 */
/*   Updated: 2024/01/18 12:00:20 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../common/common.h"

typedef enum e_ops
{
	PA = 1,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	SA,
	SB,
	SS
}		t_ops;

// main.c
int		main(int argc, char *argv[]);

// parse_and_check.c
void	parse_instructions(t_list **instruction_stack, t_list **a_head);
size_t	instruction_to_num(char *buffer);
void	apply_instructions(t_list *instructions, t_list **a_head, t_list **b_head);

#endif
