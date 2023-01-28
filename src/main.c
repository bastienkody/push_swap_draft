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

int	main(int argc, char **argv)
{
	if (argc < 2 || checker(argc, argv))
		return (1);
	ft_fprintf(1, "Arguments are corrects\n");
}

/* check : non digit or duplicate -->return(1) && int overflow -->exit() */
int	checker(int argc, char **argv)
{
	int	i;
	int	argc_tmp;
	int	values[argc];

	argc_tmp = argc;
	while (--argc_tmp > 0)
	{
		i = 0;
		while (argv[argc_tmp][i])
		{
			if (i == 0 && (argv[argc_tmp][i] == '+' || argv[argc_tmp][i] == '-'))
				i++;
			if (!ft_isdigit(argv[argc_tmp][i++]))
			{
				ft_fprintf(2, "Error (number:\"%s\")\n", argv[argc_tmp]);
				return (1);
			}
		}
		values[argc_tmp] = ft_atoi_novflw(argv[argc_tmp]);
		ft_fprintf(1, "%i\n", values[argc_tmp]);
	}
	if (check_duplicate(argc, values))
		return (1);	
	return (0);
}
/* maxi bugs for 0

bastienguillaume@Bastiens-MBP push_swap % ./push_swap 0 1 02 03 08 5 6 7 8 9
9
8
7
6
5
8
3
2
1
0
Duplicate : 0 (i==0) vs 0 (j==1)
bastienguillaume@Bastiens-MBP push_swap % 
*/
int	check_duplicate(int argc, int values[])
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (values[i] == values[j])
			{
				ft_fprintf(2, "Duplicate : %i (i==%i) vs %i (j==%i)\n", values[i], i, values[j], j);
				return (1);
			}
			j++;
		}
	}
	return (0);
}
