/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:32:21 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/02 18:43:17 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_nb **stack, char c)
{
	if (!is_sorted(*stack))
		swap(stack, c);
}

void	sort_three(t_nb **stack, char c)
{
	int	t[3];

	t[0] = (*stack)->val;
	t[1] = (*stack)->next->val;
	t[2] = (*stack)->next->next->val;

	if (is_sorted(*stack))
		return ;
	if (t[0] < t[1] && t[0] < t[2] && t[1] > t[2]) // 1 -> 3 -> 2
	{
		swap(stack, c);
		rotate(stack, c);
	}
	if (t[0] < t[1] && t[0] > t[2] && t[1] > t[2]) // 2 -> 3 -> 1
		r_rotate(stack, c);
	if (t[0] > t[1] && t[0] < t[2] && t[1] < t[2]) // 2 -> 1 -> 3
		swap(stack, c);
	if (t[0] > t[1] && t[0] > t[2] && t[1] > t[2]) // 3 -> 2 -> 1
	{
		rotate(stack, c);
		swap(stack, c);
	}
	if (t[0] > t[1] && t[0] > t[2] && t[1] < t[2]) // 3-> 1 -> 2
		rotate(stack, c);
}

void	sort_five(t_nb **stack_a, t_nb **stack_b)
{
	ft_fprintf(1, "first nb of stack_a:%i\n", (*stack_a)->val);
	ft_fprintf(1, "addresse de stack_b:%p\n", *stack_b);
}

void	sort_few(t_nb **stack_a, t_nb **stack_b, int argc)
{
	if (is_sorted(*stack_a))
		return ; 
	if (argc == 3)
		sort_two(stack_a, 'a');
	if (argc == 4)
		sort_three(stack_a, 'a');
	if (argc == 6)
		sort_five(stack_a, stack_b);
}
