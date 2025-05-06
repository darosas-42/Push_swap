/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:28:35 by darosas-          #+#    #+#             */
/*   Updated: 2025/04/30 19:28:38 by darosas-         ###   ########.fr       */
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
	int	tmp;
	int	i;

	i = 0;
	if (msg[1] == 'a')
	{
		while (stacks->a[i])
			i++;
		while (i > -1)
		{
			
		}
	}
	if (msg[1] == 'b')
	{
		while (stacks->b[i])
			i++;
	}
}

void	rotate(char *msg, t_stacks *stacks)
{

}
