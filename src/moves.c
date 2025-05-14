/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:28:35 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/13 18:17:00 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stacks *stacks, char *msg)
{
	if (msg[1] == 'a' || msg[1] == 's')
	{
		stacks->tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = stacks->tmp;
	}
	if (msg[1] == 'b' || msg[1] == 's')
	{
		stacks->tmp = stacks->a[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = stacks->tmp;
	}
	ft_printf("%s\n", msg);
}

void	push(t_stacks *stacks, char *msg)
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
	}
	ft_printf("%s\n", msg);
}

void	rotate(t_stacks *stacks, char *msg)
{
	stacks->i = -1;
	if (msg[1] == 'a' || msg[1] == 'r')
	{
		stacks->tmp = stacks->a[0];
		while (++stacks->i < stacks->a_size - 1)
			stacks->a[stacks->i] = stacks->a[stacks->i + 1];
		stacks->a[stacks->i] = stacks->tmp;
	}
	if (msg[1] == 'b' || msg[1] == 'r')
	{
		stacks->i = -1;
		stacks->tmp = stacks->b[0];
		while (++stacks->i < stacks->b_size - 1)
			stacks->b[stacks->i] = stacks->b[stacks->i + 1];
		stacks->b[stacks->i] = stacks->tmp;
	}
	ft_printf("%s\n", msg);
}

void	rev_rotate(t_stacks *stacks, char *msg)
{
	stacks->i = stacks->a_size;
	if (msg[2] == 'a' || msg[2] == 'r')
	{
		stacks->tmp = stacks->a[stacks->a_size - 1];
		while (--stacks->i > 0)
			stacks->a[stacks->i] = stacks->a[stacks->i - 1];
		stacks->a[0] = stacks->tmp;
	}
	if (msg[2] == 'b' || msg[2] == 'r')
	{
		stacks->i = stacks->b_size;
		stacks->tmp = stacks->b[0];
		while (--stacks->i < 0)
			stacks->b[stacks->i] = stacks->b[stacks->i - 1];
		stacks->b[0] = stacks->tmp;
	}
	ft_printf("%s\n", msg);
}
