/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:05:29 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/13 21:32:07 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	*good_a;
	int	a_size;
	int	b_size;
	int	index;
	int	tmp;
	int	i;
}	t_stacks;

void	error_ps(t_stacks *stacks);
void	initialize_args(t_stacks *stacks);
void	splitting_args(char *str, t_stacks *stacks);
void	good_stack(t_stacks *stacks);
void	swap(char *msg, t_stacks *stacks);
void	push(char *msg, t_stacks *stacks);
void	rotate(char *msg, t_stacks *stacks);
void	rev_rotate(char *msg, t_stacks *stacks);

#endif
