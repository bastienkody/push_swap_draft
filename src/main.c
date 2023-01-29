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
	t_nb	*start;

	if (argc < 2 || checker(argc, argv))
		return (1);
	ft_fprintf(1, "Arguments are corrects\n");
	start = nb_to_list(argc, argv);
	nb_lstprint(start);
	check_duplicate(argc, start);
	nb_lstclear(&start);
}
