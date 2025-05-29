/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:45:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/29 14:06:38 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void init_arr(int *arr, char *res, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = 0;
		i++;
	}
	res[0] = '\0';
}

void ft_sort_str(char *s, int len)
{
	int	i;
	int swapped;
	char tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len - i)
		{
			if (s[i] > s[i + 1])
			{
				tmp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	permutation(char *sorted, int *used, char *res, int len, int pos)
{
	int i;

	if (len == pos)
	{
		res[pos] = '\0';
		puts(res);
		return ;
	}
	i = 0;
	while (i < len)
	{
		if (used[i] == 0)
		{
			if (!(i > 0 && sorted[i] == sorted[i - 1] && used[i - 1] == 0))
			{
				res[pos] = sorted[i];
				used[i] = 1;
				permutation(sorted, used, res, len, pos + 1);
				used[i] = 0;
			}
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	len;
	int	*used;
	char *res;

	if (ac != 2 || av[1][0] == '\0')
		return (puts("Error: incorrec args."), 2);
	len = ft_strlen(av[1]);
	ft_sort_str(av[1], len);
	used = malloc(sizeof(int) * len);
	res = malloc(sizeof(char) * len + 1);
	if (!used || !res)
		return (puts("Error: malloc allocation."), 1);
	init_arr(used, res, len);
	permutation(av[1], used, res, len, 0);
	free(used);
	free(res);
	return (0);
}
