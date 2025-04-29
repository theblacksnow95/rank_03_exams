/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_n_queens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:53:19 by emurillo          #+#    #+#             */
/*   Updated: 2025/04/22 11:36:46 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	check_space(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col || board[i] == col - (row - i) || board[i] == col + (row - i))
			return (0);
		i++;
	}
	return (1);
}

static void	print(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i != n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

static void	n_queens(int row, int n, int *board)
{
	int	col;

	col = 0;
	while (col < n)
	{
		if (check_space(board, row, col))
		{
			board[row] = col;
			if (row == n - 1)
				print(board, n);
			else
				n_queens(row + 1, n, board);
		}
		++col;
	}
}

int	main(int ac, char **av)
{
	int	n;

	if (ac != 2)
		return (printf("Error: Wrong number of arguments\n"), 1);
	n = atoi(av[1]);
	int	board[n];
	if (n < 1)
		return (printf("Error: Wrong number of queens\n"), 1);
	n_queens(0, n, board);
	return (0);
}

