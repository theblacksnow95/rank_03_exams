/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:06:02 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/22 14:31:21 by emurillo         ###   ########.fr       */
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

void	init_res(char *res, char *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		res[i] = arr[i];
		i++;
	}
	res[i] = '\0';
}

int	valid_str(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] != '(' && arr[i] != ')')
			return (0);
		i++;
	}
	return (1);
}

int	balanced(char *res, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ()
		i++;
	}

}

void	permutation(char *res, char *arr, int len)
{

	if	(balanced(res, len))
	{
		puts(res);
		return ;
	}

}

int	main(int ac, char **av)
{
	int	len;

	if (ac != 2 || av[1][0] == '\0')
		return (1);
	if (!valid_str(av[1]))
		return (puts("Error: arg should contain only '()'"), 1);
	len = ft_strlen(av[1]);
	char res[len + 1];
	init_res(res, av[1], len);
	permutation(res, av[1], len);
	puts(res);
}
