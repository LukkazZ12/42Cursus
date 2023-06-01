/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:06:15 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/01 17:37:12 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacksecondlast(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	ft_stacklast(*stack)->next = new;
}

void	ascending_order(t_stack **stack)
{
	t_stack	*stack_aux;

	stack_aux = *stack;
	if (stack_aux->next == NULL)
	{
		free_stack(stack);
		exit(0);
	}
	while (stack_aux->next->index - stack_aux->index == 1)
	{
		stack_aux = stack_aux->next;
		if (stack_aux->next == NULL)
		{
			free_stack(stack);
			exit(0);
		}
	}
}
