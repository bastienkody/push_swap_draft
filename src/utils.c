/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:14:28 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/26 17:56:22 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_atoi_novflw(const char *nptr)
{
	int	sign;
	int	res;
	int	old_res;

	sign = 1;
	if (!ft_strncmp(nptr, "-2147483648", ft_strlen(nptr)))
		return (-2147483648);
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		old_res = res;
		res = res * 10 + (*nptr++ - '0');
		if (res < old_res)
		{
			ft_fprintf(2, "Error (Int overflow)\n");
			exit(EXIT_FAILURE);
		}
	}
	return (res * sign);
}

int	is_sorted(t_nb *stack_a)
{
	t_nb	*tmp;

	while (stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->val > tmp->val)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

t_nb	*find_bigst(t_nb *stack_a)
{
	t_nb	*tmp;
	t_nb	*bigst;

	while (stack_a && stack_a->index != -1)
		stack_a = stack_a->next;
	bigst = stack_a;
	while (stack_a && stack_a->index != -1)
		stack_a = stack_a->next;
	tmp = stack_a;
	while (tmp)
	{
		if (bigst->val < tmp->val && tmp->index == -1)
			bigst = tmp;
		tmp = tmp->next;
	}
	return (bigst);
}

void	set_index(t_nb *stack, int argc)
{
	int		idx;
	t_nb	*tmp;

	idx = argc - 1 - 1; // a.out + idx vs stock
	tmp = stack;
	while (idx > -1)
	{
		tmp = find_bigst(stack);
		if (!tmp)
			return ;
		tmp->index = idx;
		idx--;
	}
}
