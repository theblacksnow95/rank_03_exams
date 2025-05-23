/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:57:07 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/23 16:03:59 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void buble_sort(int *arr, int len)
{
	int	i;
	int	tmp;
	int	swapped;

	i = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int *copy_set(int *subset, int len)
{
	int i;
	int *copy;

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
	copy = copy_set(subset, len);
	if (!copy)
		return ;
	buble_sort(copy, len);
	while(i < len)
	{
		printf("%d", copy[i]);
		if (i < len - 1)
			printf(" ");
		i++;
	}
	free(copy);
	printf("\n");
}


void powerset(int *set, int set_size, int n, int sum, int index, int *subset, int subset_size)
{
	if (sum == n)
	{
		print_subset(subset, subset_size);
		return ;
	}
	if (sum > n || index >= set_size)
		return ;
	subset[subset_size] = set[index];
	powerset(set, set_size, n, sum + set[index], index + 1, subset, subset_size + 1);
	powerset(set, set_size, n, sum, index + 1, subset, subset_size);
}

int	main(int ac, char **av)
{
	int	n;
	int	set_size;
	int	*set;
	int	*subset;
	int	i;

	i = 0;
	if (ac < 4 || !av[1])
		return (printf("Error: Non valid args.\n"), 1);
	n = atoi(av[1]);
	if (!is_numeric(av[1]))
		return (printf("Error: (n) should be numeric.\n"), 1);
	set_size = ac - 2;
	set = malloc(sizeof(int) * set_size);
	subset = malloc (sizeof(int) * set_size);
	if (!set || !subset)
		return (printf("Error: malloc allocation.\n"), 1);
	while (i < set_size)
	{
		if (!is_numeric(av[i + 2]))
			return (printf("Error: (set) should be numeric.\n"), 1);
		set[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(set, set_size, n, 0, 0, subset, 0);
	free(set);
	free(subset);
	return (0);
}
