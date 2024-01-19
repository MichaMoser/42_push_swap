/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:44:33 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/16 15:43:12 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_list **a_head, bool print)
{
	shift_up(a_head);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_list **b_head, bool print)
{
	shift_up(b_head);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_list **a_head, t_list **b_head, bool print)
{
	shift_up(a_head);
	shift_up(b_head);
	if (print)
		ft_printf("rr\n");
}

void	rra(t_list **a_head, bool print)
{
	shift_down(a_head);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_list **b_head, bool print)
{
	shift_down(b_head);
	if (print)
		ft_printf("rrb\n");
}
