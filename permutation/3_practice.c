/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:36:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/23 15:01:58 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_arr(int *arr, char *res, int len)
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

void	sort_str(char *str, int len)
{
	int	i;
	int	swapped;
	char tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len - 1)
		{
			if (str[i] > str[i + 1])
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

void permutation(char *sorted, char *res, int *used, int len, int pos)
{
	int	i;

	if (pos == len)
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
				permutation(sorted, res, used, len, pos + 1);
				used[i] = 0;
			}
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		len;
	int		*used;
	char	*res;

	if (ac != 2 || av[1][0] == '\0')
		return (puts("Error: invalid arguments."), 1);
	len = ft_strlen(av[1]);
	used = malloc(sizeof(int) * len);
	res = malloc(sizeof(char) * len + 1);
	sort_str(av[1], len);
	init_arr(used, res, len);
	permutation(av[1], res, used, len, 0);
	free(used);
	free(res);
	return (0);
}
