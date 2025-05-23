/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:11:23 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/23 16:35:26 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


int	*copy_set(int *set, int len)
{
	int	i;
	int *copy;

	i = 0;
	if (!set || len < 1)
		return (NULL);
	copy = malloc(sizeof(int) * len);
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = set[i];
		i++;
	}
	return (copy);
}

void sort_set(int *set, int len)
{
	int	i;
	int	swapped;
	int	tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len -1)
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

void	print_set(int *subset, int len)
{
	int	i;
	int *copy;

	copy = copy_set(subset, len);
	if (copy == NULL)
		return ;
	sort_set(copy, len);
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

void	powerset(int *set, int n, int len, int sum, int idx, int *subset, int sub_len)
{
	if (sum == n)
	{
		print_set(subset, sub_len);
		return ;
	}
	if (sum > n || idx >= len)
		return ;
	subset[sub_len] = set[idx];
	powerset(set, n, len, sum + set[idx], idx + 1, subset, sub_len + 1);
	powerset(set, n, len, sum, idx + 1, subset, sub_len);
}


int	check_duplicates(int *set, int len)
{
	int	i;
	int	j;
	int	n;
	int	count;

	i = 0;
	while (i < len)
	{
		count = 0;
		n = set[i];
		j = 0;
		while (set[j])
		{
			if (set[j] == n)
			{
				count++;
			}
			j++;
			if (count > 1)
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int n;
	int i;
	int *set;
	int *subset;
	int len;

	if (ac < 4 || !av[1])
		return (printf("Error: incorrect arguments.\n"), 2);
	if (!is_numeric(av[1]))
		return (printf("Error: (n) must be numeric"), 2);
	n = atoi(av[1]);
	len = ac - 2;
	set = malloc(sizeof(int) * len);
	subset = malloc(sizeof(int) * len);
	if (!set || !subset)
		return (printf("Error: allocation error.\n"), 1);
	i = 0;
	while (i < len)
	{
		if (!is_numeric(av[i + 2]))
		return (printf("Error: set must be numeric.\n"), 2);
		set[i] = atoi(av[i + 2]);
		i++;
	}
	if (!check_duplicates(set, len))
		return (printf("Error: no duplicates allowed in set.\n"), 2);
	powerset(set, n, len, 0, 0, subset, 0);
	free(set);
	free(subset);
	return (0);
}
