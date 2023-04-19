/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_to_five_radix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:55:03 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/19 20:34:37 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_numbers(t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		swap(stack, 'a');
}

void	three_numbers(t_stack **stack)
{
	if (((*stack)->index == 0 && (*stack)->next->index == 2)
		|| ((*stack)->index == 2 && (*stack)->next->index == 4))
	{
		rrotate(stack, 'a');
		swap(stack, 'a');
	}
	else if (((*stack)->index == 1 && (*stack)->next->index == 0)
		|| ((*stack)->index == 3 && (*stack)->next->index == 2))
		swap(stack, 'a');
	else if (((*stack)->index == 1 && (*stack)->next->index == 2)
		|| ((*stack)->index == 3 && (*stack)->next->index == 4))
		rrotate(stack, 'a');
	else if (((*stack)->index == 2 && (*stack)->next->index == 0)
		|| ((*stack)->index == 4 && (*stack)->next->index == 2))
		rotate(stack, 'a');
	else if (!((*stack)->index == 2 && (*stack)->next->index == 3))
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
}

void	four_or_five_numbers(t_stack **stack_a, t_stack **stack_b, int arg)
{
	int	i;

	i = 0;
	while (i < arg)
	{
		if ((*stack_a)->index <= 1)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		i++;
	}
	if (arg == 4)
		two_numbers(stack_a);
	else
		three_numbers(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap(stack_b, 'b');
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}

static int	get_max_bit(int arg)
{
	int	max_bit;

	max_bit = 0;
	while (arg != 0)
	{
		max_bit++;
		arg = arg >> 1;
	}
	return (max_bit);
}

void	radix(t_stack **stack_a, t_stack **stack_b, int arg)
{
	int	i;
	int	max_bit;
	int	arg_aux;

	max_bit = get_max_bit(arg - 1);
	i = 0;
	while (i < max_bit)
	{
		arg_aux = arg;
		while (arg_aux > 0)
		{
			if (((*stack_a)->index >> i & 1) == 0)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a, 'a');
			arg_aux--;
		}
		while (*stack_b)
			push(stack_b, stack_a, 'a');
		ascending_order(stack_a);
		i++;
	}
}
