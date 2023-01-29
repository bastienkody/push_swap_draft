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

/* check : non digit -->return(1) && int overflow -->exit(FAILURE) */
int	checker(int argc, char **argv)
{
	int	i;
	int	tmp;
	int	*values;

	tmp = argc;
    values = malloc((argc - 1) * sizeof(int));
    if (!values)
        exit(EXIT_FAILURE);
	while (--tmp > 0)
	{
		i = 0;
		while (argv[tmp][i])
		{
			if (i == 0 && (argv[tmp][i] == '+' || argv[tmp][i] == '-'))
				i++;
			if (!ft_isdigit(argv[tmp][i++]))
			{
				ft_fprintf(2, "Error (number:\"%s\")\n", argv[tmp]);
				return (1);
			}
		}
		ft_atoi_novflw(argv[tmp]);
	}
	return (0);
}

/*ft_fprintf(1, "%i\n", values[tmp - 1]);
		values[tmp - 1] = ft_atoi_novflw(argv[tmp]);
	}
	if (check_duplicate(argc, values))
		return (1);	*/

int	check_duplicate(int argc, int values[])
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			ft_fprintf(1, "values[%i]:%i, value[%i]:%i\n", i, values[i], j, values[j]);
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

t_list  *nb_to_list(int argc, char **argv)
{
    t_nb    *nb;
    t_list  *start;

    start = malloc(1 * sizeof(t_list));
    if (!start)
        exit(EXIT_FAILURE);
    while (--argc > 1)
    {
        nb = malloc(1 * sizeof(t_nb));
        if (!nb)
            ft_lstclear(&start, ft_lstdelone);
        nb->val = ft_atoi(++argv);
        ft_lstadd_back(&start, ft_lstnew(nb));



}


