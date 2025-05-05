/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:47:57 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/05 18:25:46 by darosas-         ###   ########.fr       */
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
}

/* void	splitting_args(char *str, t_stacks *stacks)
{
	char	**matrix;
	int		i;
	int		j;

	matrix = ft_split(str, ' ');
	if (!matrix)
		error_ps(stacks);
	i = 0;
	while (matrix[i])
	{
		stacks->a[stacks->index] = ft_atoi(matrix[i]);
		stacks->index++;
		i++;
	}
} */

void	perfect_ps(t_stacks *stacks)
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
}
