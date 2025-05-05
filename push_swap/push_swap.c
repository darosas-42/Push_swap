/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:05:33 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/05 19:35:33 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_ps(t_stacks *stacks)
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
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	valid_args(char **argv, t_stacks *stacks)
{
	int	i;
	int	j;
	
	i = 0;
	stacks->a_size = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-')
			{
				if (!(ft_isdigit(argv[i][j])))
					error_ps(stacks);
			}
			if ((argv[i][j] == ' ' || argv[i][j] == '+' || argv[i][j] == '-')
			&& (ft_isdigit(argv[i][j + 1])))
				stacks->a_size++;
			if ((argv[i][j] == '+' || argv[i][j] == '-')
			&& !(ft_isdigit(argv[i][j + 1])))
				error_ps(stacks);
		}
		stacks->a_size++;
	}
	return (1);
}

static void	getting_args(char **argv, t_stacks *stacks)
{
	char	**matrix;
	int		i;
	int		j;
	int		x;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == ' ')
			{
				matrix = ft_split(argv[i], ' ');
				if (!matrix)
					error_ps(stacks);
				x = -1;
				while (matrix[++x])
					stacks->a[stacks->index++] = ft_atoi(matrix[x]);
			}
		}
		stacks->a[stacks->index++] = ft_atoi(argv[i]);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	
	if (argc < 2)
		error_ps(NULL);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		error_ps(NULL);
	valid_args(argv, stacks);
	initialize_args(stacks);
	getting_args(argv, stacks);
	return (0);
}
