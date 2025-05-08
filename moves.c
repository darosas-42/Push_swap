/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:28:35 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/08 21:42:38 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *msg, t_stacks *stacks)
{
	if (msg[1] == 'a' || msg[1] == 's')
	{
		stacks->tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = stacks->tmp;
		if (msg[1] == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "ss\n", 3);
	}
	if (msg[1] == 'b' || msg[1] == 's')
	{
		stacks->tmp = stacks->a[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = stacks->tmp;
		if (msg[1] == 'b')
			write(1, "sb\n", 3);
	}
}

void	push(char *msg, t_stacks *stacks)
{
	if (msg[1] == 'b')
	{
		stacks->i = ++stacks->b_size;
		while (--stacks->i > 0)
			stacks->b[stacks->i] = stacks->b[stacks->i - 1];
		stacks->b[0] = stacks->a[0];
		stacks->i = -1;
		stacks->a_size--;
		while (++stacks->i < stacks->a_size)
			stacks->a[stacks->i] = stacks->a[stacks->i + 1];
		write(1, "pb\n", 3);
	}
	else
	{
		stacks->i = ++stacks->a_size;
		while (--stacks->i > 0)
			stacks->a[stacks->i] = stacks->a[stacks->i - 1];
		stacks->a[0] = stacks->b[0];
		stacks->i = -1;
		stacks->b_size--;
		while (++stacks->i < stacks->b_size)
			stacks->b[stacks->i] = stacks->b[stacks->i + 1];
		write(1, "pa\n", 3);
	}
}

void	rotate(char *msg, t_stacks *stacks)
{
	stacks->i = -1;
	if (msg[1] == 'a' || msg[1] == 'r')
	{
		stacks->tmp = stacks->a[0];
		while (++stacks->i < stacks->a_size - 1)
			stacks->a[stacks->i] = stacks->a[stacks->i + 1];
		stacks->a[stacks->i] = stacks->tmp;
		if (msg[1] == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rr\n", 3);
	}
	if (msg[1] == 'b' || msg[1] == 'r')
	{
		stacks->i = -1;
		stacks->tmp = stacks->b[0];
		while (++stacks->i < stacks->b_size - 1)
			stacks->b[stacks->i] = stacks->b[stacks->i + 1];
		stacks->b[stacks->i] = stacks->tmp;
		if (msg[1] == 'b')
			write(1, "rb\n", 3);
	}
}

void	rev_rotate(char *msg, t_stacks *stacks)
{
	stacks->i = stacks->a_size;
	if (msg[2] == 'a' || msg[2] == 'r')
	{
		stacks->tmp = stacks->a[stacks->a_size - 1];
		while (--stacks->i > 0)
			stacks->a[stacks->i] = stacks->a[stacks->i - 1];
		stacks->a[0] = stacks->tmp;
		if (msg[2] == 'a')
			write(1, "rra\n", 4);
		else
			write(1, "rrr\n", 4);
	}
	if (msg[2] == 'b' || msg[2] == 'r')
	{
		stacks->i = stacks->b_size;
		stacks->tmp = stacks->b[0];
		while (--stacks->i < 0)
			stacks->b[stacks->i] = stacks->b[stacks->i - 1];
		stacks->b[0] = stacks->tmp;
		if (msg[2] == 'b')
			write(1, "rrb\n", 4);
	}
}
