/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:48:21 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/22 12:13:36 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	sort_str(char *str, int len)
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
			if (str[i] > str[i + 1])
			{
				tmp = str[i + 1];
				str[i + 1] = str[i];
				str[i] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	init_arr(char *res, int *used, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		used[i] = 0;
		i++;
	}
	res[0] = '\0';
}

void	permutation(char *av, int *used, char *res, int len)
{
	int	i;

	i = 0;
	if (ft_strlen(res) == len)
	{
		puts(res);
		return ;
	}
	while (i < len)
	{
		if (!used[i])
		{
			res[ft_strlen(res)] = av[i];
			used[i] = 1;
			res[ft_strlen(res) + 1] = '\0';
			permutation(av, used, res, len);
			used[i] = 0;
			res[ft_strlen(res) - 1] = '\0';
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
	sort_str(av[1], len);
	int	used[len];
	char res[len + 1];
	init_arr(res, used, len);
	permutation(av[1], used, res, len);
	return (0);
}
