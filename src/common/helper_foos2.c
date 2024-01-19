/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper_foos2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 16:52:23 by mmoser        #+#    #+#                 */
/*   Updated: 2024/01/18 12:00:00 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

size_t	ft_max(size_t n1, size_t n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

size_t	ft_min(size_t n1, size_t n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

void	free_and_exit(t_list **list1, t_list **list2, t_list **list3,
		bool exit_code)
{
	ft_lstclear(list1);
	ft_lstclear(list2);
	ft_lstclear(list3);
	if (exit_code == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

bool	check_order(t_list *stack)
{
	if (!stack)
		return (ERROR);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (ERROR);
		stack = stack->next;
	}
	return (0);
}
