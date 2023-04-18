/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_to_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:55:03 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/17 21:59:28 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_numbers(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		swap(stack_a, 'a');
}

void	three_numbers(t_stack **stack_a)
{
	if ((*stack_a)->index == 0 && (*stack_a)->next->index == 2)
	{
		rrotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	else if ((*stack_a)->index == 1 && (*stack_a)->next->index == 0)
		swap(stack_a, 'a');
	else if ((*stack_a)->index == 1 && (*stack_a)->next->index == 2)
		rrotate(stack_a, 'a');
	else if ((*stack_a)->index == 2 && (*stack_a)->next->index == 0)
		rotate(stack_a, 'a');
	else
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

void	four_or_five_numbers(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if ((*stack_a)->index <= 1)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		i++;
	}
	if (argc == 5)
		two_numbers(stack_a);
	else
		three_numbers(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap(stack_b, 'b');
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}