/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:05:29 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/07 21:50:02 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
	int	index;
	int	*good_a;
}	t_stacks;

void	error_ps(t_stacks *stacks);
void	initialize_args(t_stacks *stacks);
void	splitting_args(char *str, t_stacks *stacks);
void	good_stack(t_stacks *stacks);
void	perfect_ps(t_stacks *stacks);

#endif
