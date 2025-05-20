/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:28:48 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/19 21:36:23 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < (stacks->a_size - 1))
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_stacks *stacks)
{
	if (stacks->a[2] != 2)
	{
		if (stacks->a[0] == 2)
			rotate(stacks, "ra");
		else
			rev_rotate(stacks, "rra");
	}
	if (stacks->a[0] > stacks->a[1])
		swap(stacks, "sa");
}

void	sort_four_to_five(t_stacks *stacks)
{
	while (stacks->b_size < 2)
	{
		if (stacks->a[0] == 0 || stacks->a[0] == 1)
			push(stacks, "pb");
		else
			rotate(stacks, "ra");
	}
	if (stacks->a[2] != 4 && stacks->a_size == 3)
	{
		if (stacks->a[0] == 4)
			rotate(stacks, "ra");
		else
			rev_rotate(stacks, "rra");
	}
	if (stacks->a[0] > stacks->a[1])
		swap(stacks, "sa");
	if (stacks->b[0] < stacks->b[1])
		swap(stacks, "sb");
	push(stacks, "pa");
	push(stacks, "pa");
}

static void	radix_sort_stack_b(t_stacks *stacks, int bits)
{
	int	i;

	i = stacks->b_size;
	while (i-- && (stacks->index + 1) < bits && !is_sorted(stacks))
	{
		if (((stacks->b[0] >> (stacks->index + 1)) & 1) == 1)
			push(stacks, "pa");
		else
			rotate(stacks, "rb");
	}
	if (is_sorted(stacks))
	{
		while (stacks->b_size > 0)
			push(stacks, "pa");
	}
}

void	radix_sort(t_stacks *stacks)
{
	int	bits;

	stacks->i = stacks->a_size;
	bits = 1;
	while (stacks->i > 1)
	{
		stacks->i /= 2;
		bits++;
	}
	stacks->index = -1;
	while (++stacks->index < bits)
	{
		stacks->i = stacks->a_size;
		while (stacks->i-- > 0 && !is_sorted(stacks))
		{
			if (((stacks->a[0] >> stacks->index) & 1) == 0)
				push(stacks, "pb");
			else
				rotate(stacks, "ra");
		}
		radix_sort_stack_b(stacks, bits);
	}
	while (stacks->b_size > 0)
		push(stacks, "pa");
}
