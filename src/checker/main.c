/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:03:06 by mmoser            #+#    #+#             */
/*   Updated: 2024/02/22 09:44:31 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;
	t_list	*instructions;

	if (argc - 1 == 0)
		return (0);
	a_head = NULL;
	b_head = NULL;
	instructions = NULL;
	parse_instructions(&instructions);
	parse_input (argc - 1, argv, &a_head);
	apply_instructions(instructions, &a_head, &b_head);
	if (check_order(a_head) == 0 && b_head == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_and_exit(&instructions, &a_head, &b_head, EXIT_SUCCESS);
}
