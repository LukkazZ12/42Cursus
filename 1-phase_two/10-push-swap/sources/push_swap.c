/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:06:15 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/25 22:03:47 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*stack_aux;

	while (*stack)
	{
		stack_aux = (*stack)->next;
		free(*stack);
		*stack = stack_aux;
	}
}

static void	read_numbers(t_stack **stack, int argv)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
	{
		if (stack != NULL)
			free_stack(stack);
		error();
	}
	new->number = argv;
	new->index = 0;
	new->next = NULL;
	ft_stackadd_back(stack, new);
}

static void	set_index(t_stack *stack_a)
{
	t_stack	*stack_copy;
	t_stack	*stack_aux;

	stack_copy = stack_a;
	while (stack_a)
	{
		stack_aux = stack_copy;
		while (stack_aux)
		{
			if (stack_a->number > stack_aux->number)
				(stack_a->index)++;
			stack_aux = stack_aux->next;
		}
		stack_a = stack_a->next;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_arg(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
		read_numbers(&stack_a, ft_atoll(argv[i++]));
	set_index(stack_a);
	ascending_order(&stack_a);
	if (argc == 3)
		two_numbers(&stack_a);
	else if (argc == 4)
		three_numbers(&stack_a);
	else if (argc >= 5 && argc <= 6)
		four_or_five_numbers(&stack_a, &stack_b, argc - 1);
	else
		radix(&stack_a, &stack_b, argc - 1);
	free_stack(&stack_a);
	return (0);
}
