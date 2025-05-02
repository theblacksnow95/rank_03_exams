/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:07:42 by emurillo          #+#    #+#             */
/*   Updated: 2025/04/30 14:52:43 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	all_numeric(char **av)
{
	int	i;

	i = 2;
	while (av[i])
	{
		if (!is_numeric(av[i]))
			return (0);
		i++;
	}
	return (1);
}
/* void	copy_args_to_set(char **av, int *set, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (is_numeric(av[i]))
			set[i] = atoi(av[i]);
		else
			return ;
		i++;
	}
} */

int	fill_set(char **av, int *set, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		set[i] = atoi(av[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	n;
	int	size;
	int	*set;
	int	j;

	if (ac < 4)
		return (printf("Error: Incorrect arguments.\n"), 1);
	if (!is_numeric(av[1]))
		return (printf("Error: n should be numeric.\n"), 1);
	if (!all_numeric(av))
		return (printf("Error: non numeric args.\n"), 1);
	n = atoi(av[1]);
	size = ac - 2;
	set = malloc(sizeof(int) * size);
	fill_set(&av[2], set, size);
	j = 0;
	while (j < size)
		printf("{%d}", set[j++]);
	printf("\n");
	printf("%d\n", n);
	free(set);
	return (0);
}
