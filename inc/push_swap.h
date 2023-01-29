/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:59:20 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/26 12:01:05 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
 
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct nb
{
    int index;
    int val;
}               t_nb;

int	checker(int argc, char **argv);
int	check_duplicate(int argc, int values[]);
int	ft_atoi_novflw(const char *nptr);

#endif
