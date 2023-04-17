/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:30:02 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/17 20:03:14 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*stack_aux;

	stack_aux = NULL;
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

void	rotate(t_stack **stack, char c)
{
	t_stack	*stack_aux;

	stack_aux = *stack;
	*stack = (*stack)->next;
	ft_stacklast(*stack)->next = stack_aux;
	stack_aux->next = NULL;
	if (c == 'a' || c == 'b')
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	r_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 's');
	rotate(stack_b, 's');
	ft_putstr_fd("rr", 1);
}

void	rrotate(t_stack **stack, char c)
{
	t_stack	*stack_aux;

	stack_aux = *stack;
	*stack = ft_stacklast(*stack);
	ft_stacksecondlast(stack_aux)->next = NULL;
	(*stack)->next = stack_aux;
	if (c == 'a' || c == 'b')
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	r_rrotate(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a, 's');
	rrotate(stack_b, 's');
	ft_putstr_fd("rrr", 1);
}
