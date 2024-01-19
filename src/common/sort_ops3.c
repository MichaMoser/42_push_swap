/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:44:33 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/16 15:43:30 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rrr(t_list **a_head, t_list **b_head, bool print)
{
	shift_down(a_head);
	shift_down(b_head);
	if (print)
		ft_printf("rrr\n");
}
