/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:07:38 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/29 19:30:22 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_numeric(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if(s[i] == '-')
			i++;
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dups(int *set, int size)
{
	int i;
	int n;
	int count;
	int j;

	i = 0;
	while (i < size)
	{
		n = set[i];
		count = 0;
		i++;
		j = 0;
		while (j < size )
		{
			if (set[j] == n)
				count++;
			if (count > 1)
				return (0);
			j++;
		}
	}
	return (1);
}

int *dup_set(int *subset, int len)
{
	int i;
	int	*copy;

	i = 0;
	if (!subset || !len )
		return (NULL);
	copy = malloc(sizeof(int) * len);
	if (!copy)
		return (printf("Error: malloc allocation.\n"), NULL);
	while (i < len)
	{
		copy[i] = subset[i];
		i++;
	}
	return (copy);
}

void sort_set(int *set, int len)
{
	int	i;
	int	swapped;
	int tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len - 1)
		{
			if (set[i] > set[i + 1])
			{
				tmp = set[i];
				set[i] = set[i + 1];
				set[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

void print_set(int *subset, int len)
{
	int	i;
	int *copy;

	i = 0;
	copy = dup_set(subset, len);
	if (!copy)
		return ;
	sort_set(copy, len);
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

void	powerset(int *set, int n, int size, int sum, int idx, int *subset, int len)
{
	if (idx == size)
	{
		if (sum == n)
		{
			print_set(subset, len);
		}
		return ;
	}
	subset[len] = set[idx];
	powerset(set, n, size, sum + set[idx], idx + 1, subset, len + 1);
	powerset(set, n, size, sum, idx + 1, subset, len);
}

int	main(int ac, char **av)
{
	int	n;
	int	*set;
	int	*subset;
	int	size;
	int	i;

	if (ac < 4 || !av[1])
		return (printf("Error: incorrect args.\n"), 2);
	if (!is_numeric(av[1]))
		return (printf("Error; (n) must be numeric.\n"), 2);
	n = atoi(av[1]);
	size = ac - 2;
	set = malloc(sizeof(int) * size);
	subset = malloc(sizeof(int) * size);
	if (!set || !subset)
		return (printf("Error: malloc allocation.\n"), 1);
	i = 0;
	while (i < size)
	{
		if (!is_numeric(av[i + 2]))
			return (printf("Error: set must be numeric.\n"), 2);
		set[i] = atoi(av[i + 2]);
		i++;
	}
	if (!check_dups(set, size))
		return (printf("Error: No duplicates allowed.\n"), 2);
	powerset(set, n, size, 0, 0, subset, 0);
	free(set);
	free(subset);
	return (0);
}
