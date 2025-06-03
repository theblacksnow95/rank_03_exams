/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_practice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:39:41 by emurillo          #+#    #+#             */
/*   Updated: 2025/06/03 11:51:30 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_numeric(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int *board, int n)
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

int	check_spaces(int row, int col, int *board)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if(board[i] == col ||
			board[i] == col + (row - i) ||
			board[i] == col - (row - i))
			return (0);
		i++;
	}
	return (1);
}

void	n_queens(int *board, int n, int row)
{
	int	col;

	col = 0;
	while (col < n)
	{
		if (check_spaces(row, col, board))
		{
			board[row] = col;
			if (row == n - 1)
				print_board(board, n);
			else
				n_queens(board, n, row + 1);
		}
		++col;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*board;

	if (ac != 2 || !av[1])
		return (1);
	if (!is_numeric(av[1]))
		return (1);
	n = atoi(av[1]);
	if (n < 1)
		return (printf("Error: non positive queens.\n"), 1);
	board = malloc(sizeof(int) * n);
	if (!board)
		return (1);
	n_queens(board, n, 0);
	free(board);
	return  (0);
}
