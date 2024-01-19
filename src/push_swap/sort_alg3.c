/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:02:25 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/19 16:24:15 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_max_value(t_list *head)
{
	int		max;
	size_t	position;
	size_t	i;

	i = 0;
	max = head->num;
	position = 0;
	while (head)
	{
		if (head->num > max)
		{
			max = head->num;
			position = i;
		}
		head = head->next;
		i++;
	}
	return (position);
}

void	shift_to_top(t_list **head, size_t i, size_t size)
{
	if (i < size / 2)
	{
		while (i > 0)
		{
			rb(head, true);
			i--;
		}
	}
	else
	{
		while (size - i > 0)
		{
			rrb(head, true);
			i++;
		}
	}
}
