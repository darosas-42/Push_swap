/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:05:33 by darosas-          #+#    #+#             */
/*   Updated: 2025/04/30 21:11:09 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_ps(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->a)
			free(stacks->a);
		if (stacks->b)
			free(stacks->b);
		free(stacks);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	valid_args(char **matrix)
{

}

static char	**splitting_args(char **argv, t_stacks *stacks)
{
	char	**matrix;
	int		i;

	i = 0;
	while (argv[++i])
	{
		matrix = ft_split(argv[i], ' '); // cambiar
	}
	if (matrix)
	valid_args(matrix);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	
	if (argc < 2)
		ft_error_ps(NULL);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_error_ps(NULL);
	
}
