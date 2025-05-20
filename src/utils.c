/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:47:57 by darosas-          #+#    #+#             */
/*   Updated: 2025/05/20 17:50:51 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_args(t_stacks *stacks)
{
	stacks->a = malloc(stacks->a_size * sizeof(int));
	if (!stacks->a)
		free_exit(stacks, "Error");
	stacks->b = malloc(stacks->a_size * sizeof(int));
	if (!stacks->b)
		free_exit(stacks, "Error");
	stacks->good_a = malloc(stacks->a_size * sizeof(int));
	if (!stacks->good_a)
		free_exit(stacks, "Error");
	stacks->index = 0;
	stacks->b_size = 0;
}

int	ft_atoi_ps(const char *s, t_stacks *stacks)
{
	int			i;
	long int	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (s[i] == ' ' || s[i] == '\f' || s[i] == '\n' || s[i] == '\r'
		|| s[i] == '\t' || s[i] == '\v')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = (nb * 10) + (s[i] - 48);
		i++;
	}
	nb *= neg;
	if (nb > INT_MAX || nb < INT_MIN)
		free_exit(stacks, "Error");
	return (nb);
}

void	splitting_args(char *str, t_stacks *stacks)
{
	char	**matrix;
	int		i;
	int		x;

	matrix = ft_split(str, ' ');
	if (!matrix)
		free_exit(stacks, "Error");
	x = 0;
	while (matrix[x])
		stacks->a[stacks->index++] = ft_atoi(matrix[x++]);
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

static void	indexing(t_stacks *stacks)
{
	stacks->i = -1;
	while (++stacks->i < stacks->a_size)
	{
		stacks->index = -1;
		while (++stacks->index < stacks->a_size)
		{
			if (stacks->good_a[stacks->index] == stacks->a[stacks->i])
			{
				stacks->a[stacks->i] = stacks->index;
				break ;
			}
		}
	}
}

void	good_stack(t_stacks *stacks)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while ((i + 1) < stacks->a_size)
	{
		j = i + 1;
		while (j < stacks->a_size)
		{
			if (stacks->good_a[i] == stacks->good_a[j])
				free_exit(stacks, "Error");
			if (stacks->good_a[i] > stacks->good_a[j])
			{
				swap = stacks->good_a[i];
				stacks->good_a[i] = stacks->good_a[j];
				stacks->good_a[j] = swap;
			}
			j++;
		}
		i++;
	}
	indexing(stacks);
}
