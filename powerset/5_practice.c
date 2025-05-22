/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:21:53 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/21 14:26:08 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int	bubble_sort(int	*subset, int len)
{
	int	i;
	int	swapped;
	int	tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len - 1)
		{
			if (subset[i] > subset[i + 1])
			{
				tmp = subset[i];
				subset[i] = subset[i + 1];
				subset[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
	return (0);
}

int *copy_subset(int *subset, int len)
{
	int	i;
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

int print_subset(int *subset, int len)
{
	int	i;
	int	*copy;

	i = 0;
	copy = copy_subset(subset, len);
	if (copy == NULL)
		return (1);
	bubble_sort(copy, len);
	while (i < len)
	{
		printf("%d", copy[i]);
		if (i < len - 1)
			printf(" ");
		i++;
	}
	printf("\n");
	free(copy);
	return (0);
}

void	powerset(int *set, int n, int size, int sum, int idx, int *subset, int subset_len)
{
	if (sum == n)
	{
		print_subset(subset, subset_len);
		return ;
	}
	if (sum > n || idx >= size)
		return ;
	subset[subset_len] = set[idx];
	powerset(set, n, size, sum + set[idx], idx + 1, subset, subset_len + 1);
	powerset(set, n, size, sum, idx + 1, subset, subset_len);
}

int	main(int ac, char **av)
{
	int	i;
	int	n;
	int	len;
	int	*set;
	int	*subset;

	if (ac < 4 || !av[1] || !is_numeric(av[1]))
		return (printf("Error: invalid arguments.\n"), 1);
	n = atoi(av[1]);
	len = ac - 2;
	set = malloc(sizeof(int) * len);
	subset = malloc(sizeof(int) * len);
	if (!set || !subset)
		return (printf("Error: malloc allocation.\n"), 1);
	i = 0;
	while (i < len)
	{
		if (!is_numeric(av[i + 2]))
			return (printf("Error: set must be numeric.\n"), 1);
		set[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(set, n, len, 0, 0, subset, 0);
	free(set);
	free(subset);
	return (0);
}
