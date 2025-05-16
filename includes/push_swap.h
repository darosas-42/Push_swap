/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:05:29 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/16 21:36:04 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

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

void	free_exit(t_stacks *stacks, char *msg);
void	initialize_args(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);
void	splitting_args(char *str, t_stacks *stacks);
void	good_stack(t_stacks *stacks);
void	swap(t_stacks *stacks, char *msg);
void	push(t_stacks *stacks, char *msg);
void	rotate(t_stacks *stacks, char *msg);
void	rev_rotate(t_stacks *stacks, char *msg);
void	sort_three(t_stacks *stacks);
void	sort_four_to_five(t_stacks *stacks);
void	radix_sort(t_stacks *stacks);
int		ft_atoi_ps(const char *s, t_stacks *stacks);

#endif
