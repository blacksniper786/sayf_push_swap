/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_up_to_5_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:54:27 by sahamzao          #+#    #+#             */
/*   Updated: 2024/08/06 20:45:20 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_up_to_5(int *a, int *b, int *size_a, int *size_b)
{
	int		*reverse;
	t_node	t_node;

	t_node.range = ft_range(*size_a);
	reverse = malloc(sizeof(int) * (*size_a));
	ft_copy(a, reverse, *size_a);
	ft_reverse(reverse, *size_a);
	while (*size_a)
	{
		if (ft_find(a[0], reverse, *size_a) < t_node.id_range)
		{
			ft_pb(a, b, size_a, size_b);
			ft_first_operation(b, size_b, 0);
		}
		else if ((ft_find(a[0], reverse, *size_a) >= t_node.id_range)
			&& (ft_find(a[0], reverse, *size_a) <= t_node.range))
		{
			ft_pb(a, b, size_a, size_b);
			ft_first_operation(b, size_b, 1);
		}
		else if (ft_find(a[0], reverse, *size_a) > t_node.range)
			ft_ra(a, *size_a);
	}
	ft_final_operation(a, b, size_a, size_b);
	free(reverse);
}

int	ft_range(int size)
{
	int	range;

	range = 0;
	if (size > 5 && size <= 16)
		range = 5;
	else if ((size > 16 && size <= 100) || (size >= 100 && size < 500))
		range = 25;
	else if (size >= 500)
		range = 35;
	return (range);
}

void	ft_first_operation(int *b, int *size_b, int e)
{
	t_node	t_node;

	t_node.id_range = 0;
	if (e == 0)
	{
		ft_rb(b, *size_b);
		t_node.id_range++;
		t_node.range++;
	}
	else
	{
		t_node.id_range++;
		t_node.range++;
	}
}

void	ft_final_operation(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	great;

	while (*size_b)
	{
		i = (*size_b / 2);
		great = the_great(b, *size_b);
		if (great == 0)
			ft_pa(a, b, size_a, size_b);
		else if (great < i)
		{
			while (great > 0)
			{
				ft_rb(b, *size_b);
				great--;
			}
			ft_pa(a, b, size_a, size_b);
		}
		else if (great >= i)
			ft_norminette_help(a, b, size_a, size_b);
	}
}

void	ft_norminette_help(int *a, int *b, int *size_a, int *size_b)
{
	int	great;

	great = the_great(b, *size_b);
	while (great < *size_b)
	{
		ft_rrb(b, *size_b);
		great++;
	}
	ft_pa(a, b, size_a, size_b);
}
