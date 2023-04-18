/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:05:40 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/17 21:59:05 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacksecondlast(t_stack *stack);
void	swap(t_stack **stack, char c);
void	s_swap(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_src, t_stack **stack_dst, char c);
void	rotate(t_stack **stack, char c);
void	r_rotate(t_stack **stack_a, t_stack **stack_b);
void	rrotate(t_stack **stack, char c);
void	r_rrotate(t_stack **stack_a, t_stack **stack_b);
void	two_numbers(t_stack **stack_a);
void	three_numbers(t_stack **stack_a);
void	four_or_five_numbers(t_stack **stack_a, t_stack **stack_b, int argc);

#endif