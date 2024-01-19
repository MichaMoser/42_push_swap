/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 17:06:10 by mmoser        #+#    #+#                 */
/*   Updated: 2024/01/18 11:48:43 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../common/common.h"

typedef struct s_shifts
{
	size_t	ra;
	size_t	rra;
	size_t	rb;
	size_t	rrb;
	size_t	rr;
	size_t	rrr;
}			t_shifts;

// main.c
void		print_stacks(t_list *a_head, t_list *b_head);

// sort_alg1.c
void		sort_stacks(size_t size, t_list **a_head, t_list **b_head);
void		sort_for_three(t_list **a_head);
void		sort_for_five(t_list **a_head, t_list **b_head);
void		find_two_smallest(t_list *stack, t_list **smallest,
				t_list **scnd_smallest);
// sort_alg2.c
void		insertion_sort(size_t size, t_list **a_head, t_list **b_head);
t_shifts	get_min_shifts(t_list *a_head, t_list *b_head, size_t size_a,
				size_t size_b);
size_t		get_insertion_gap(int num, t_list *head);
size_t		set_opt_shifts(t_shifts *current);
void		shift_stacks(t_shifts shifts, t_list **a_head, t_list **b_head);
// sort_alg3.c
void		shift_to_top(t_list **head, size_t i, size_t size);
size_t		find_max_value(t_list *head);

#endif
