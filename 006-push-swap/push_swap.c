/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:06:15 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/17 21:58:42 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->number, 1);
		ft_putstr_fd(", index: ", 1);
		ft_putnbr_fd(stack->index, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

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

void	read_numbers(t_stack **stack, int argv)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->number = argv;
	new->index = 0;
	new->next = NULL;
	ft_stackadd_back(stack, new);
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			j;
	long long	num;

	j = 0;
	while ((nptr[j] >= 9 && nptr[j] <= 13) || nptr[j] == 32)
		j++;
	i = j;
	if (nptr[i] != '-' && nptr[i] != '+' && ft_isdigit(nptr[i]) == 0)
		return (0);
	else if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (ft_isdigit(nptr[i + 1]) == 0)
			return (0);
		i++;
	}
	num = 0;
	while (ft_isdigit(nptr[i]) == 1)
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[j] == '-')
		num = -num;
	return (num);
}

void	check_duplicate(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_putstr_fd("ERROR: There is a duplicate ", 1);
				ft_putstr_fd("number in the arguments.", 1);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	ascending_order(t_stack *stack_a)
{
	if (stack_a->next == NULL)
		exit (0);
	while ((stack_a->next)->index - stack_a->index == 1)
	{
		stack_a = stack_a->next;
		if (stack_a->next == NULL)
			exit (0);
	}
}

void	check_argv(char *argv[])
{
	int			i;
	int			j;
	long long	n;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (ft_isdigit(argv[i][j]))
			j++;
		n = ft_atoll(argv[i]);
		if (argv[i][j] != '\0' || argv[i][0] == '\0'
			|| n < -2147483648
			|| n > 2147483647)
		{
			ft_putstr_fd("ERROR: There is a invalid ", 1);
			ft_putstr_fd("number in the arguments.", 1);
			exit (1);
		}
		i++;
	}
	check_duplicate(argv);
}

void	set_index(t_stack *stack_a)
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

	if (argc < 2)
	{
		ft_putstr_fd("ERROR: Wrong number of arguments.", 1);
		return (1);
	}
	check_argv(argv);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		read_numbers(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	set_index(stack_a);
	ascending_order(stack_a);
	print_stack(stack_a);
	ft_putchar_fd('\n', 1);
	if (argc == 3)
		two_numbers(&stack_a);
	else if (argc == 4)
		three_numbers(&stack_a);
	else if (argc >= 5 && argc <= 6)
		four_or_five_numbers(&stack_a, &stack_b, argc);
	print_stack(stack_a);
}
