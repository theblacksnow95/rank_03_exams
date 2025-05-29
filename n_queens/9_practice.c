/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:07:24 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/29 15:25:56 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void print_board(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i < n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int	check_spaces(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col ||
			board[i] == col + (row - i) ||
			board[i] == col - (row - i))
			return (0);
		i++;
	}
	return (1);
}

void	n_queens(int *board, int n, int row)
{
	int	 col;

	col = 0;
	while (col < n)
	{
		if (check_spaces(board, row, col))
		{
			board[row] = col;
			if (row == n - 1)
				print_board(board, n);
			else
				n_queens(board, n, row + 1);
		}
		col++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*board;

	if (ac != 2 || !av[1])
		return (printf("Error: invalid args.\n"), 2);
	n = atoi(av[1]);
	if (n < 1)
		return (printf("Error: incorrect queen number.\n"), 2);
	board = malloc(sizeof(int) * n);
	n_queens(board, n, 0);
	free(board);
	return (0);
}
