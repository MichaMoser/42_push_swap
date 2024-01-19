/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   common.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 13:29:59 by mmoser        #+#    #+#                 */
/*   Updated: 2024/01/19 09:25:17 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../../libft/src/ft_printf/ft_printf.h"
# include "../../libft/src/get_next_line/get_next_line.h"
# include "../../libft/src/libft/libft.h"

# define ERROR 1

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}					t_list;

// parsing.c
int					is_duplicate(int num, t_list *head);
void				parse_input(size_t size, char *argv[], t_list **a_head);

// lst_ops1.c
t_list				*ft_lstnew(int n);
void				ft_lstadd_front(t_list **lst, t_list *new_node);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
// lst_ops2.c
void				ft_lstclear(t_list **lst);

// sort_ops1.c
void				sa(t_list **a_head, bool print);
void				sb(t_list **b_head, bool print);
void				ss(t_list **a_head, t_list **b_head, bool print);
void				pa(t_list **b_head, t_list **a_head, bool print);
void				pb(t_list **a_head, t_list **b_head, bool print);
// sort_ops2.c
void				ra(t_list **a_head, bool print);
void				rb(t_list **b_head, bool print);
void				rra(t_list **a_head, bool print);
void				rrb(t_list **b_head, bool print);
void				rr(t_list **a_head, t_list **b_head, bool print);
// sort_ops3.c
void				rrr(t_list **a_head, t_list **b_head, bool print);

// helper_foos1.c
int					safe_atoi(const char *str, bool *error_flag);
void				switch_first_two(t_list **head);
void				push(t_list **head_src, t_list **head_dest);
void				shift_up(t_list **head);
void				shift_down(t_list **head);

// helper_foos2.c
size_t				ft_max(size_t n1, size_t n2);
size_t				ft_min(size_t n1, size_t n2);
void				free_and_exit(t_list **list1, t_list **list2,
						t_list **list3, bool exit_code);
bool				check_order(t_list *stack);

#endif
