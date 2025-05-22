/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:48:06 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/22 12:11:11 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void display_permutation(char *sorted, int *used, char *res, int len)
{
	if (ft_strlen(res) == len)
	{
		puts(res);
		return ;
	}
	int i = 0;
	while (i < len)
	{
		if (!used[i])
		{
			//use sorted[i] and mark it as 1(used)
			res[ft_strlen(res)] = sorted[i];
			used[i] = 1;
			res[ft_strlen(res) + 1] = '\0';

			display_permutation(sorted, used, res, len);
			//unmark last char
			used[i] = 0;
			//rm  last char from res
			res[ft_strlen(res) - 1] = '\0';
		}
		i++;
	}
}

void sort_str(char *s)
{
	int i = 0;
	int j;
	char temp;

	while (s[i])
	{
		j = 0;
		while (s[j+1])
		{
			if (s[j] > s[j+1])
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
			j++;
		}
		i++;
	}
}

void init_arr(int *int_arr, char *s, int len)
{
	int i = 0;
	while (i < len)
	{
		int_arr[i] = 0;
		i++;
	}
	s[0] = '\0';
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		return (1);
	int len = ft_strlen(av[1]);
	sort_str(av[1]);
	// printf("sorted: %s", av[1]);

	int used[len];
	char res[len+1];
	init_arr(used, res, len);
	display_permutation(av[1], used, res, len);
}
