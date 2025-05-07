/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:28:35 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/07 19:48:22 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *msg, t_stacks *stacks)
{
	int	tmp;

	if (msg[1] == 'a' || msg[1] == 's')
	{
		tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = tmp;
		if (msg[1] == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "ss\n", 3);

	}
	if (msg[1] == 'b' || msg[1] == 's')
	{
		tmp = stacks->a[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = tmp;
		if (msg[1] == 'b')
			write(1, "sb\n", 3);
	}
}

void	push(char *msg, t_stacks *stacks)
{
	int	i;

	if (msg[1] == 'b')
	{
		i = ++stacks->b_size;
		while (--i > 0)
			stacks->b[i] = stacks->b[i - 1];
		stacks->b[0] = stacks->a[0];
		i = -1;
		while (++i < --stacks->a_size)
			stacks->a[i] = stacks->a[i + 1];
		write(1, "pb\n", 3);
	}
	else
	{
		i = ++stacks->a_size;
		while (--i > 0)
			stacks->a[i] = stacks->a[i - 1];
		stacks->a[0] = stacks->b[0];
		i = -1;
		while (++i < --stacks->b_size)
			stacks->b[i] = stacks->b[i + 1];
		write(1, "pa\n", 3);
	}
}

void	rotate(char *msg, t_stacks *stacks)
{

}
