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

/* stack_B == empty && stack_a == sorted */
int	is_sorted(t_nb *stack_a, t_nb *stack_b)
{
	t_nb	*tmp;

	if (stack_b || !stack_a)
		return (1);
	while (stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->val > tmp->val)
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}
