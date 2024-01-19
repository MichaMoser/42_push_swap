/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:34:48 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/17 14:06:38 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

int	is_duplicate(int num, t_list *head)
{
	while (head != NULL)
	{
		if (num == head->num)
			return (1);
		head = head->next;
	}
	return (0);
}

void	parse_input(size_t size, char *argv[], t_list **a_head)
{
	bool	error;
	int		num;
	t_list	*new;
	size_t	i;

	i = 0;
	while (i < size)
	{
		error = false;
		num = safe_atoi(argv[i + 1], &error);
		if (error || is_duplicate(num, *a_head) || argv[i + 1][0] == '\0')
			free_and_exit(a_head, NULL, NULL, EXIT_FAILURE);
		new = ft_lstnew(num);
		if (!new)
			free_and_exit(a_head, NULL, NULL, EXIT_FAILURE);
		ft_lstadd_back(a_head, new);
		i++;
	}
}
