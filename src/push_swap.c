/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:05:33 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/20 19:25:20 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_stacks *stacks, char *msg)
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
	if (msg[0] == 'E')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

static void	valid_args2(char **argv, t_stacks *stacks, int i, int j)
{
	if (argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-')
	{
		if (!(ft_isdigit(argv[i][j])))
			free_exit(stacks, "Error");
	}
	if (((argv[i][j] == ' ' || argv[i][j] == '+' || argv[i][j] == '-')
	&& ft_isdigit(argv[i][j + 1])) || (j == 0 && ft_isdigit(argv[i][j])))
		stacks->a_size++;
	if ((argv[i][j] == '+' || argv[i][j] == '-')
	&& !(ft_isdigit(argv[i][j + 1])))
		free_exit(stacks, "Error");
	if ((argv[i][j] == '+' || argv[i][j] == '-')
	&& ft_isdigit(argv[i][j + 1]) && ft_isdigit(argv[i][j - 1]))
		free_exit(stacks, "Error");
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
		if (argv[i][0] == '\0')
			free_exit(stacks, "Error");
		while (argv[i][++j])
			valid_args2(argv, stacks, i, j);
	}
	return (1);
}

static void	getting_args(char **argv, t_stacks *stacks)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == ' ')
			{
				splitting_args(argv[i], stacks);
				break ;
			}
		}
		if (argv[i][j] == ' ')
			continue ;
		stacks->a[stacks->index++] = ft_atoi_ps(argv[i], stacks);
	}
	i = -1;
	while (++i < stacks->a_size)
		stacks->good_a[i] = stacks->a[i];
	good_stack(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 1)
		free_exit(NULL, "Error");
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		free_exit(NULL, "Error");
	valid_args(argv, stacks);
	initialize_args(stacks);
	getting_args(argv, stacks);
	if (is_sorted(stacks) == 1 || stacks->a_size == 1)
		free_exit(stacks, "");
	if (stacks->a_size == 2)
		swap(stacks, "sa");
	else if (stacks->a_size == 3)
		sort_three(stacks);
	else if (stacks->a_size == 4 || stacks->a_size == 5)
		sort_four_to_five(stacks);
	else
		radix_sort(stacks);
	if (!(is_sorted(stacks)))
		free_exit(stacks, "Error");
	free_exit(stacks, "");
	return (0);
}
