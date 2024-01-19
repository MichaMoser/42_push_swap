/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:03:27 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/19 16:20:06 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_instructions(t_list **instruction_stack, t_list **a_head)
{
	char	*buffer;
	t_list	*new;
	t_ops	instruction;

	while (1)
	{
		buffer = get_next_line(0);
		if (!buffer)
			return ;
		instruction = instruction_to_num(buffer);
		free(buffer);
		if (instruction == false)
			free_and_exit(instruction_stack, a_head, NULL, EXIT_FAILURE);
		new = ft_lstnew(instruction);
		if (!new)
			free_and_exit(instruction_stack, a_head, NULL, EXIT_FAILURE);
		ft_lstadd_back(instruction_stack, new);
	}
}

size_t	instruction_to_num(char *buffer)
{
	if (ft_strncmp(buffer, "pa\n", 3) == 0)
		return (PA);
	else if (ft_strncmp(buffer, "pb\n", 3) == 0)
		return (PB);
	else if (ft_strncmp(buffer, "ra\n", 3) == 0)
		return (RA);
	else if (ft_strncmp(buffer, "rb\n", 3) == 0)
		return (RB);
	else if (ft_strncmp(buffer, "rr\n", 3) == 0)
		return (RR);
	else if (ft_strncmp(buffer, "rra\n", 4) == 0)
		return (RRA);
	else if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		return (RRB);
	else if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		return (RRR);
	else if (ft_strncmp(buffer, "sa\n", 3) == 0)
		return (SA);
	else if (ft_strncmp(buffer, "sb\n", 3) == 0)
		return (SB);
	else if (ft_strncmp(buffer, "ss\n", 3) == 0)
		return (SS);
	else
		return (false);
}

void	apply_instructions(t_list *instructions, t_list **a_head, t_list **b_head)
{
	while (instructions)
	{
		if (instructions->num == PA)
		pa(b_head, a_head, false);
		else if (instructions->num == PB)
			pb(a_head, b_head, false);
		else if (instructions->num == RA)
			ra(a_head, false);
		else if (instructions->num == RB)
			rb(b_head, false);
		else if (instructions->num == RR)
			rr(a_head, b_head, false);
		else if (instructions->num == RRA)
			rra(a_head, false);
		else if (instructions->num == RRB)
			rrb(b_head, false);
		else if (instructions->num == RRR)
			rrr(a_head, b_head, false);
		else if (instructions->num == SA)
			sa(a_head, false);
		else if (instructions->num == SB)
			sb(b_head, false);
		else
			ss(a_head, b_head, false);
		instructions = instructions->next;
	}
}
