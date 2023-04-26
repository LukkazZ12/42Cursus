/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:05:40 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/25 22:04:10 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
long long		ft_atoll(const char *nptr);
void			check_arg(int argc, char *argv[]);
void			error(void);
t_stack			*ft_stacklast(t_stack *stack);
t_stack			*ft_stacksecondlast(t_stack *stack);
void			ft_stackadd_back(t_stack **stack, t_stack *new);
void			ascending_order(t_stack **stack);
void			free_stack(t_stack **stack);
void			swap(t_stack **stack, char c);
void			s_swap(t_stack **stack_a, t_stack **stack_b);
void			push(t_stack **stack_src, t_stack **stack_dst, char c);
void			rotate(t_stack **stack, char c);
void			r_rotate(t_stack **stack_a, t_stack **stack_b);
void			rrotate(t_stack **stack, char c);
void			r_rrotate(t_stack **stack_a, t_stack **stack_b);
void			two_numbers(t_stack **stack);
void			three_numbers(t_stack **stack);
void			four_or_five_numbers(t_stack **stack_a,
					t_stack **stack_b, int arg);
void			radix(t_stack **stack_a, t_stack **stack_b, int arg);

#endif