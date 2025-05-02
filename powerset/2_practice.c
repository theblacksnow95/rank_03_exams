/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:04:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/01 15:39:47 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*buble_sort(int *subset, int len)
{
	int	i;
	int	swapped;
	int	temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len)
		{
			if (subset[i] > subset[i + 1])
			{
				temp = subset[i];
				subset[i] = subset[i + 1];
				subset[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
	return (subset);
}

int	is_numeric(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	all_is_numeric(char **av)
{
	int	i;

	i = 2;
	while (av[i])
	{
		if (!is_numeric(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*copy_subset(int *subset, int len)
{
	int	i;
	int	*copy;

	i = 0;
	copy = malloc(sizeof(int) * len);
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = subset[i];
		i++;
	}
	return (copy);
}

void	print_subset(int *subset, int len)
{
	int	i;
	int	*copy;

	i = 0;
	copy = copy_subset(subset, len);
	if (!copy)
		return ;
	buble_sort(copy, len);
	while (i < len)
	{
		printf("%d", copy[i]);
		if (i < len - 1)
			printf(" ");
		i++;
	}
	printf("\n");
	free(copy);
}

void	powerset(int *set, int size, int n, int sum, int idx, int *subset, int len)
{
	if (sum == n)
	{
		print_subset(subset, len);
		return ;
	}
	if (sum > n || idx >= size)
		return ;
	subset[len] = set[idx];
	powerset(set, size, n, sum + set[idx], idx + 1, subset, len + 1);
	powerset(set, size, n, sum, idx + 1, subset, len);
}

int	main(int ac, char **av)
{
	int	n;
	int	i;
	int	size;
	int	*set;
	int	*subset;

	if (ac < 4 || !av[1])
		return (printf("Error: non valid arguments.\n"), 1);
	if (!is_numeric(av[1]))
		return (printf("Error: (n) should be an int.\n"), 1);
	size = ac - 2;
	n = atoi(av[1]);
	set = malloc(sizeof(int) * size);
	subset = malloc(sizeof(int) * size);
	if (!set || !subset)
		return (printf("Error: Malloc allocation.\n"), 1);
	i = 0;
	while (i < size)
	{
		if (!is_numeric(av[i + 2]))
			return (printf("Error: set must be numeric.\n"));
		set[i] = atoi(av[i + 2]);
		i++;
	}
	print_subset(set, size);
	powerset(set, size, n, 0, 0, subset, 0);
	free(set);
	free(subset);
	return (0);
}
