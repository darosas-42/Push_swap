/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:28:35 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/16 19:29:32 by darosas-         ###   ########.fr       */
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
		stacks->tmp = ++stacks->b_size;
		while (--stacks->tmp > 0)
			stacks->b[stacks->tmp] = stacks->b[stacks->tmp - 1];
		stacks->b[0] = stacks->a[0];
		stacks->tmp = -1;
		stacks->a_size--;
		while (++stacks->tmp < stacks->a_size)
			stacks->a[stacks->tmp] = stacks->a[stacks->tmp + 1];
	}
	else
	{
		stacks->tmp = ++stacks->a_size;
		while (--stacks->tmp > 0)
			stacks->a[stacks->tmp] = stacks->a[stacks->tmp - 1];
		stacks->a[0] = stacks->b[0];
		stacks->tmp = -1;
		stacks->b_size--;
		while (++stacks->tmp < stacks->b_size)
			stacks->b[stacks->tmp] = stacks->b[stacks->tmp + 1];
	}
	ft_printf("%s\n", msg);
}

void	rotate(t_stacks *stacks, char *msg)
{
	int	i;

	i = -1;
	if (msg[1] == 'a' || msg[1] == 'r')
	{
		stacks->tmp = stacks->a[0];
		while (++i < stacks->a_size - 1)
			stacks->a[i] = stacks->a[i + 1];
		stacks->a[i] = stacks->tmp;
	}
	if (msg[1] == 'b' || msg[1] == 'r')
	{
		i = -1;
		stacks->tmp = stacks->b[0];
		while (++i < stacks->b_size - 1)
			stacks->b[i] = stacks->b[i + 1];
		stacks->b[i] = stacks->tmp;
	}
	ft_printf("%s\n", msg);
}

void	rev_rotate(t_stacks *stacks, char *msg)
{
	int	i;

	i = stacks->a_size;
	if (msg[2] == 'a' || msg[2] == 'r')
	{
		stacks->tmp = stacks->a[stacks->a_size - 1];
		while (--i > 0)
			stacks->a[i] = stacks->a[i - 1];
		stacks->a[0] = stacks->tmp;
	}
	if (msg[2] == 'b' || msg[2] == 'r')
	{
		i = stacks->b_size;
		stacks->tmp = stacks->b[0];
		while (--i < 0)
			stacks->b[i] = stacks->b[i - 1];
		stacks->b[0] = stacks->tmp;
	}
	ft_printf("%s\n", msg);
}
