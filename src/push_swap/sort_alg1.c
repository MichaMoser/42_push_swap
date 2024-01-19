/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_alg1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/05 09:08:58 by mmoser        #+#    #+#                 */
/*   Updated: 2024/01/18 11:49:43 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_two_smallest(t_list *stack, t_list **smallest,
		t_list **scnd_smallest)
{
	*smallest = stack;
	*scnd_smallest = stack->next;
	while (stack)
	{
		if (stack->num < (*smallest)->num)
		{
			*scnd_smallest = *smallest;
			*smallest = stack;
		}
		else if (stack->num < (*scnd_smallest)->num && stack != *smallest)
			*scnd_smallest = stack;
		stack = stack->next;
	}
}

void	sort_for_five(t_list **a_head, t_list **b_head)
{
	t_list	*smallest;
	t_list	*scnd_smallest;
	size_t	size_a;

	find_two_smallest(*a_head, &smallest, &scnd_smallest);
	size_a = 5;
	while (size_a > 3)
	{
		if (*a_head == smallest || *a_head == scnd_smallest)
		{
			pb(a_head, b_head, true);
			size_a--;
		}
		else
			ra(a_head, true);
	}
	if ((*b_head)->num < (*b_head)->next->num)
		sb(b_head, true);
	sort_for_three(a_head);
	pa(b_head, a_head, true);
	pa(b_head, a_head, true);
}

void	sort_for_three(t_list **a_head)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = (*a_head);
	second = (*a_head)->next;
	third = (*a_head)->next->next;
	if (first->num < third->num && first->num > second->num)
		sa(a_head, true);
	else if (first->num < second->num && first->num > third->num)
		rra(a_head, true);
	else if (third->num < first->num && third->num > second->num)
		ra(a_head, true);
	else if (third->num < second->num && third->num > first->num)
	{
		rra(a_head, true);
		sa(a_head, true);
	}
	else if (second->num < first->num && second->num > third->num)
	{
		sa(a_head, true);
		rra(a_head, true);
	}
}

void	sort_stacks(size_t size, t_list **a_head, t_list **b_head)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*a_head)->num > (*a_head)->next->num)
			sa(a_head, true);
	}
	else if (size == 3)
		sort_for_three(a_head);
	else if (size == 5)
		sort_for_five(a_head, b_head);
	else
		insertion_sort(size, a_head, b_head);
}
