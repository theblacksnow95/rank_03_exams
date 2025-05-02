/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:28:48 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/01 15:31:44 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*buble_sort(int *arr, int size)
{
	int	i;
	int	sorted;
	int	tmp;

	sorted = 1;
	while (sorted)
	{
		sorted = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = 1;
			}
			i++;
		}
	}
	return (arr);
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

int	all_is_numeric(char **av, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (!is_numeric(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*copy_array(int *set, int size)
{
	int	i;
	int	*copy;

	i  = 0;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = set[i];
		i++;
	}
	return (copy);
}

void	print_subset(int *subset, int size)
{
	int	i;
	int	*copy;

	i = 0;

	copy = copy_array(subset, size);
	if (!copy)
		return ;
	buble_sort(copy, size);
	while (i < size)
	{
		printf("%d", subset[i]);
		if (i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
	free(copy);
}
/**
 * Finds all the subsets equal to n in the *set provided.
 * The return prints al the subsets sorted by line.
 * @param n number to compare to all the subsets.abort
 * @param set set of number from wich we find the subsets.
 * @param sum result of idx addition.
 * @param subset pointer to subset to store the results.
 * @param len size of subset
*/
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

	size = ac - 2;
	if (ac < 4)
		return (printf("Error: incorrect arguments number.\n"), 1);
	if (!is_numeric(av[1]))
		return (printf("Error: (n) must be numeric.\n"), 1);
	if (!all_is_numeric(av, ac))
		return (printf("Error: set must be numeric.\n"), 1 );
	set = malloc(sizeof(int) * size);
	subset = malloc(sizeof(int) * size);
	if (!set || !subset)
		return (printf("Error: malloc allocation.\n"), 1);
	n = atoi(av[1]);
	i = 0;
	while (i < size)
	{
		set[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(set, size, n, 0, 0, subset, 0);
	free(set);
	free(subset);
	return (0);
}
