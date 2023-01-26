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
	if (argc < 2)
		return (1);
	checker(argc, argv);
}

int	checker(int argc, char **argv)
{
	int	i;

	while (--argc > 0)
	{
		i = 0;/* check is_digit*/
		while (argv[argc][i])
		{
			if (i == 0 && (argv[argc][i] == '+' || argv[argc][i] == '-'))// +/- on first char only
				i++;
			if (!ft_isdigit(argv[argc][i]))
			{
				ft_fprintf(2, "Error\n(number:\"%s\")\n", argv[argc]);
				return (1);
			}
			i++;
		}
		ft_fprintf(1, "%i\n", ft_atoi_novflw(argv[argc]));
	}
	return (0);
}
