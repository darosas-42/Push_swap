/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:47:57 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/07 18:28:42 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_args(t_stacks *stacks)
{
	stacks->a = malloc(stacks->a_size * sizeof(int));
	if (!stacks->a)
		error_ps(stacks);
	stacks->b = malloc(stacks->a_size * sizeof(int));
	if (!stacks->b)
		error_ps(stacks);
	stacks->good_a = malloc(stacks->a_size * sizeof(int));
	if (!stacks->good_a)
		error_ps(stacks);
	stacks->index = 0;
	stacks->b_size = 0;
}

/*void	perfect_ps(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->a)
			free(stacks->a);
		if (stacks->b)
			free(stacks->b);
		if (stacks->good_a)
			free(stacks->good_a);
		free(stacks);
	}
	write(2, "Perfect\n", 6);
	exit(EXIT_SUCCESS);
} */

void	splitting_args(char *str, t_stacks *stacks)
{
	char	**matrix;
	int		i;
	int		x;

	matrix = ft_split(str, ' ');
	if (!matrix)
		error_ps(stacks);
	x = 0;
	while (matrix[x])
		stacks->a[stacks->index++] = ft_atoi(matrix[x++]);
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	good_stack(t_stacks *stacks)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (stacks->good_a[i + 1])
	{
		j = i + 1;
		while (stacks->good_a[j])
		{
			if (stacks->good_a[i] == stacks->good_a[j])
				error_ps(stacks);
			if (stacks->good_a[i] > stacks->good_a[j])
			{
				swap = stacks->good_a[i];
				stacks->good_a[i] = stacks->good_a[j];
				stacks->good_a[j] = swap;
				i = 0;
			}
			j++;
		}
		i++;
	}
}
