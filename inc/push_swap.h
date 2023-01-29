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

typedef struct s_nb
{
	int			index;
	int			val;
	struct s_nb	*next;
}				t_nb;

int		checker(int argc, char **argv);
int		check_duplicate(int argc, t_nb *start);
int		ft_atoi_novflw(const char *nptr);
t_nb	*nb_to_list(int argc, char **argv);
void	print_nb_list(void *nb);

t_nb	*nb_lstnew(int val);
t_nb	*nb_lstlast(t_nb *lst);
void	nb_lstadd_back(t_nb **lst, t_nb *new);
void	nb_lstclear(t_nb **lst);
void	nb_lstprint(t_nb *lst);

#endif
