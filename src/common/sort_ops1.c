/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:44:33 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/16 15:42:25 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_list **a_head, bool print)
{
	switch_first_two(a_head);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_list **b_head, bool print)
{
	switch_first_two(b_head);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_list **a_head, t_list **b_head, bool print)
{
	switch_first_two(a_head);
	switch_first_two(b_head);
	if (print)
		ft_printf("ss\n");
}

void	pa(t_list **b_head, t_list **a_head, bool print)
{
	push(b_head, a_head);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_list **a_head, t_list **b_head, bool print)
{
	push(a_head, b_head);
	if (print)
		ft_printf("pb\n");
}
