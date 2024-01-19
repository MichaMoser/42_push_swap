/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_foos1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:52:23 by mmoser            #+#    #+#             */
/*   Updated: 2024/01/19 16:18:00 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

#define overflow num > INT_MAX / 10 || (num >= INT_MAX / 10 && ((sign == 1 && str[i] > '7') || (sign == -1 && str[i] > '8')))

int	safe_atoi(const char *str, bool *error_flag)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (overflow)
			*error_flag = true;
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || (i == 1 && (str[0] == '+' || str[0] == '-')))
		*error_flag = true;
	return ((int)(num * sign));
}

void	switch_first_two(t_list **head)
{
	t_list	*first;
	t_list	*scnd;

	if (ft_lstsize(*head) < 2)
		return ;
	first = *head;
	scnd = first->next;
	first->next = scnd->next;
	scnd->next = first;
	*head = scnd;
}

void	push(t_list **head_src, t_list **head_dest)
{
	t_list	*first;

	if (!ft_lstsize(*head_src))
		return ;
	first = (*head_src);
	*head_src = first->next;
	ft_lstadd_front(head_dest, first);
}

void	shift_up(t_list **head)
{
	t_list	*first;
	t_list	*last;

	if (!(*head) || ft_lstsize(*head) < 2)
		return ;
	first = *head;
	last = ft_lstlast(first);
	last->next = first;
	*head = first->next;
	first->next = NULL;
}

void	shift_down(t_list **head)
{
	t_list	*first;
	t_list	*last;
	t_list	*scnd_last;

	if (!(*head) || ft_lstsize(*head) < 2)
		return ;
	first = *head;
	last = ft_lstlast(first);
	last->next = first;
	scnd_last = first;
	while (scnd_last->next != last)
		scnd_last = scnd_last->next;
	scnd_last->next = NULL;
	(*head) = last;
}
