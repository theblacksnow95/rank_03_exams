/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:53:10 by emurillo          #+#    #+#             */
/*   Updated: 2025/04/29 17:28:42 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	buble_sort(int *arr, int size)
{
	int	i;
	int	sorted;
	int	temp;

	sorted = 1;
	while (sorted)
	{
		sorted = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				sorted = 1;
			}
			i++;
		}
	}
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	all_is_numeric(char **av, int size)
{
	int	i;

	i = 2;
	while (i < size)
	{
		if (!is_numeric(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void print_set(int *set, int size_set)
{
	int	i;

	i = 0;
	while (i < size_set)
	{
		printf("{%d}", set[i++]);
		if (1 != size_set - 1)
			printf(" ");
	}
	printf("\n");
}

void	fill_set(char **str, int size_set, int *set)
{
	int	i;

	i = 0;
	while (i < size_set)
	{
		set[i] = atoi(str[i]);
		i++;
	}
}

void	powerset(int *set, int size_set, int n, int sum, int index, int *subset, int len)
{
	if (sum == n)
	{
		buble_sort(subset, len);
		print_set(subset, len);
		return ;
	}
	if (sum > n || index >= size_set)
		return ;
	subset[len] = set[index];
	powerset(set, size_set, n, sum + set[index], index + 1, subset, len + 1 );
	powerset(set, size_set, n, sum, index + 1, subset, len);
}

int	main(int ac, char **av)
{
	int	n;
	int	*set;
	int	*subset;
	int	size_set;

	if (ac < 4 || !av[1])
		return (printf("Error: Incorrect num of args.\n"), 1);
	if (!is_numeric(av[1]))
		return (printf("Error: N, must be numeric.\n"), 1);
	size_set = ac - 2;
	if (!all_is_numeric(av, ac))
		return (printf("Error: all args must be numeric.\n"), 1);
	n = atoi(av[1]);
	set = malloc(sizeof(int) * size_set);
	subset = malloc(sizeof(int) * size_set);
	if (!set || !subset)
		return (printf("Error: malloc"), 1);
	fill_set(&av[2], size_set, set);
	powerset(set, size_set, n, 0, 0, subset, 0);
	free(set);
	return (0);
}
