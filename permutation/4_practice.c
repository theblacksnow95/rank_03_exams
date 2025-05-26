/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:13:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/26 13:20:42 by emurillo         ###   ########.fr       */
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

void	init_arr(int *arr, char *res, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		arr[i] = 0;
		i++;
	}
	res[0] = '\0';
}

void	permutation(char *sorted, int *used, char *res, int len, int pos)
{
	int	i;

	i = 0;
	if (len == pos)
	{
		res[pos] = '\0';
		puts(res);
		return ;
	}
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

void	sort_arr(char *arr, int len)
{
	int		i;
	char	tmp;
	int		swapped;

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

int	main(int ac, char **av)
{
	int		len;
	char	*res;
	int		*used;

	if (ac != 2 || av[1][0] == '\0')
		return (1);
	len = ft_strlen(av[1]);
	res = malloc(sizeof(char) * len + 1);
	used = malloc(sizeof(int) * len);
	init_arr(used, res, len);
	sort_arr(av[1], len);
	permutation(av[1], used, res, len, 0);
	free(res);
	free(used);
	return (0);
}
