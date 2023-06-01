/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:30:02 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/19 18:41:25 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*stack_aux;

	stack_aux = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	stack_aux->next = *stack;
	*stack = stack_aux;
	if (c == 'a' || c == 'b')
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	s_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	ft_putstr_fd("ss", 1);
}

void	push(t_stack **stack_src, t_stack **stack_dst, char c)
{
	t_stack	*stack_aux;

	stack_aux = (*stack_src)->next;
	(*stack_src)->next = *stack_dst;
	*stack_dst = *stack_src;
	*stack_src = stack_aux;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}
