/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:09:02 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/18 15:14:03 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;
	size_t	size;

	size = argc - 1;
	if (size == 0)
		return (0);
	a_head = NULL;
	b_head = NULL;
	parse_input (size, argv, &a_head);
	if (check_order(a_head) != 0)
		sort_stacks(argc - 1, &a_head, &b_head);
	free_and_exit(&a_head, &b_head, NULL, EXIT_SUCCESS);
}
