/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:42:13 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/26 12:07:56 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_both_stacks(t_nb *stack_a, t_nb *stack_b)
{
	ft_fprintf(1, "Both stacks\n");
	ft_fprintf(1, "stack_a\n");
	nb_lstprint(stack_a);
	ft_fprintf(1, "stack_b\n");
	nb_lstprint(stack_b);
	ft_fprintf(1, "End of both stacks\n");
}

int	main(int argc, char **argv)
{
	t_nb	*stack_a;
	t_nb	*stack_b;
 
	if (argc < 2 || checker(argc, argv))
		return (1);
	stack_a = nb_to_list(argc, argv);
	
	if(check_duplicate(argc, stack_a))
	{
		nb_lstclear(&stack_a);
		return (1);
	}
	ft_fprintf(1, "Arguments are corrects\n");

	stack_b = NULL;

	print_both_stacks(stack_a, stack_b);

	//nb_lstprint(stack_a);
	//push_a(&stack_a, &stack_b);
	//push_b(&stack_a, &stack_b);
	//push_b(&stack_a, &stack_b);
	//push_b(&stack_a, &stack_b);
	//r_rotate_both(&stack_a, &stack_b);
	//r_rotate_both(&stack_a, &stack_b);
	//rotate_both(&stack_a, &stack_b);
	//swap_both(&stack_a, &stack_b);
 
	print_both_stacks(stack_a, stack_b);

	if (is_sorted(stack_a, stack_b))
		ft_fprintf(1, "Sorted!\n");
	else
		ft_fprintf(1, "Unsorted!\n");

	nb_lstclear(&stack_a);
	nb_lstclear(&stack_b);
}
