/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:54:25 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/03 21:18:03 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	buble_sort(int *arr, int len)
{
	int	i;
	int	swap;
	int	tmp;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
	}
}

int	*copy_set(int *set, int len)
{
	int	i;
	int	*copy;

	i = 0;
	if (!set[i])
		return (NULL);
	copy = malloc(sizeof(int) * len);
	while (i < len)
	{
		copy[i] = set[i];
		i++;
	}
	return (copy);
}

void	print_set(int *subset, int len)
{
	int	i;
	int	*copy;

	copy = copy_set(subset, len);
	buble_sort(copy, len);
	if (!copy)
		return ;
	i = 0;
	while (i < len)
	{
		printf("%d", copy[i]);
		if (i < len)
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
		print_set(subset, len);
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
	int	size;
	int	i;
	int	*set;
	int	*subset;

	if (ac < 4 || !av[1])
		return (printf("Error: Incorrect args.\n"), 1);
	if (!is_numeric(av[1]))
		return (printf("Error: (N) must be numeric.\n"), 1);
	size = ac - 2;
	set = malloc(sizeof(int) * size);
	subset = malloc(sizeof(int) * size);
	if (!set || !subset)
		return (printf("Error: malloc allocation.\n"), 1);
	i = 0;
	n = atoi(av[1]);
	while (i < size)
	{
		if (!is_numeric(av[i + 2]))
			return (printf("Error: Set must be numeric.\n"), 1);
		set[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(set, size, n, 0, 0, subset, 0);
	free(set);
	free(subset);
	return (0);
}
