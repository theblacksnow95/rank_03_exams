/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:48:37 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/26 15:22:30 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_numeric(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if  (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dups(int *set, int len)
{
	int	i;
	int	j;
	int	n;
	int count;

	i = 0;
	while (i < len)
	{
		i++;
		j = 0;
		n = set[i];
		count = 0;
		while (set[j])
		{
			if (n == set[j])
				count++;
			if (count > 1)
				return (0);
			j++;
		}
	}
	return (1);
}

int	*copy_arr(int *set, int len)
{
	int	i;
	int *copy;

	i = 0;
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

void	sort_arr(int *set, int len)
{
	int	i;
	int	tmp;
	int swapped;

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

void	print_set(int *set, int len)
{
	int	i;
	int	*copy;

	i = 0;
	copy = copy_arr(set, len);
	if (!copy)
		return;
	sort_arr(copy, len);
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
	subset[sub_len] =  set[idx];
	powerset(set, n, len, sum + set[idx], idx + 1, subset, sub_len + 1);
	powerset(set, n, len, sum, idx + 1, subset, sub_len);
}

int	main(int ac, char **av)
{
	int	n;
	int	i;
	int	len;
	int	*set;
	int	*subset;

	if (ac < 4 || !av[1])
		return (printf("Error: Invalid args.\n"), 1);
	if (!is_numeric(av[1]))
		return (printf("Error: (n) must be numeric.\n"), 1);
	n = atoi(av[1]);
	len = ac - 2;
	i = 0;
	set = malloc(sizeof(int) * len);
	subset = malloc(sizeof(int) * len);
	if (!set || !subset)
		return(printf("Error: malloc allocations.\n"), 1);
	while (i < len)
	{
		if (!is_numeric(av[i + 2]))
			return (printf("Error: set must be numeric.\n"), 1);
		set[i] = atoi(av[i + 2]);
		i++;
	}
	if (!check_dups(set, len))
		return (printf("Error: no duplicates allowed.\n"), 2);
	powerset(set, n, len, 0, 0, subset, 0);
	free(subset);
	return (0);
}
