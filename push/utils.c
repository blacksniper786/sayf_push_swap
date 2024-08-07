/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:37:24 by sahamzao          #+#    #+#             */
/*   Updated: 2024/08/06 19:52:35 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chek(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) >= INT_MAX || ft_atoi(av[i]) <= INT_MIN)
		{
			write(1, "ERROR!\n", ft_strlen("ERROR\n"));
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find(int a, int *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_freeing(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_freee(int *a, int *b)
{
	free(a);
	free(b);
}

int	ft_just_for_norminette(char **maal)
{
	t_node	t_node;

	t_node.j = 0;
	while (maal[t_node.j])
	{
		t_node.k = 0;
		while (maal[t_node.j][t_node.k])
		{
			if (maal[t_node.j][0] == '-')
				t_node.k++;
			while (maal[t_node.j][t_node.k])
			{
				if (maal[t_node.j][t_node.k] < '0'
					|| maal[t_node.j][t_node.k] > '9')
				{
					write(2, "ERRORs\n", ft_strlen("ERROR\n"));
					return (0);
				}
				t_node.k++;
			}
			t_node.k++;
		}
		t_node.j++;
	}
	return (1);
}
