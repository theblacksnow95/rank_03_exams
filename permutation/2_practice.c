/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:15:55 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/22 16:44:55 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_arr(char *arr, int len)
{
	int		i;
	int		swapped;
	char	tmp;

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
			}
			i++;
		}
	}
}

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

void	permutation(char *sorted, int *used, char *res, int len, int pos)
{
	int	i;

	i = 0;
	if (pos == len)
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

int	main(int ac, char **av)
{
	int	len;

	if (ac != 2 || av[1][0] == '\0')
		return (1);
	len = ft_strlen(av[1]);
	sort_arr(av[1], len);
	int	used[len];
	char res[len + 1];
	init_arr(used, res, len);
	permutation(av[1], used, res, len, 0);
	return (0);
}
