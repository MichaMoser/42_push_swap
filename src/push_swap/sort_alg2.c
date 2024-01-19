/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:02:02 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/19 16:24:31 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stacks(t_shifts shifts, t_list **a_head, t_list **b_head)
{
	while (shifts.rr--)
		rr(a_head, b_head, true);
	while (shifts.rrr--)
		rrr(a_head, b_head, true);
	while (shifts.ra--)
		ra(a_head, true);
	while (shifts.rra--)
		rra(a_head, true);
	while (shifts.rb--)
		rb(b_head, true);
	while (shifts.rrb--)
		rrb(b_head, true);
}

size_t	set_opt_shifts(t_shifts *current)
{
	size_t	both_up;
	size_t	both_down;
	size_t	diverse;
	size_t	min_sum;

	both_up = ft_max(current->ra, current->rb);
	both_down = ft_max(current->rra, current->rrb);
	diverse = ft_min(current->ra, current->rra);
	diverse += ft_min(current->rb, current->rrb);
	if (both_up <= both_down && both_up <= diverse)
	{
		current->rr = ft_min(current->ra, current->rb);
		current->ra -= current->rr;
		current->rb -= current->rr;
		current->rra = 0;
		current->rrb = 0;
		current->rrr = 0;
		min_sum = both_up;
	}
	else if (both_down <= both_up && both_down <= diverse)
	{
		current->rrr = ft_min(current->rra, current->rrb);
		current->rra -= current->rrr;
		current->rrb -= current->rrr;
		current->ra = 0;
		current->rb = 0;
		current->rr = 0;
		min_sum = both_down;
	}
	else
	{
		if (current->ra > current->rra)
			current->ra = 0;
		else
			current->rra = 0;
		if (current->rb > current->rrb)
			current->rb = 0;
		else
			current->rrb = 0;
		current->rrr = 0;
		current->rr = 0;
		min_sum = diverse;
	}
	return (min_sum);
}

size_t	get_insertion_gap(int num, t_list *head)
{
	size_t	i;

	i = 0;
	while (head->next)
	{
		if ((num < head->num && (num > head->next->num
					|| head->num < head->next->num))
			|| (num > head->num
				&& num > head->next->num && head->num < head->next->num))
			return (i + 1);
		head = head->next;
		i++;
	}
	return (0);
}

t_shifts	get_min_shifts(t_list *a_head, t_list *b_head, size_t size_a,
		size_t size_b)
{
	size_t		i;
	t_shifts	current;
	size_t		current_sum;
	t_shifts	cheapest;
	size_t		cheapest_sum;

	i = 0;
	while (a_head)
	{
		current.ra = i;
		current.rra = size_a - i;
		current.rb = get_insertion_gap(a_head->num, b_head);
		current.rrb = size_b - current.rb;
		current_sum = set_opt_shifts(&current);
		if (current_sum < cheapest_sum || i == 0)
		{
			cheapest = current;
			cheapest_sum = current_sum;
		}
		a_head = a_head->next;
		i++;
	}
	return (cheapest);
}

void	insertion_sort(size_t size, t_list **a_head, t_list **b_head)
{
	size_t		size_a;
	size_t		size_b;
	t_shifts	min_shifts;

	pb(a_head, b_head, true);
	pb(a_head, b_head, true);
	size_a = size - 2;
	size_b = 2;
	while (size_a > 0)
	{
		min_shifts = get_min_shifts(*a_head, *b_head, size_a, size_b);
		shift_stacks(min_shifts, a_head, b_head);
		pb(a_head, b_head, true);
		size_a--;
		size_b++;
	}
	shift_to_top(b_head, find_max_value(*b_head), size_b);
	while (size_b--)
		pa(b_head, a_head, true);
}
