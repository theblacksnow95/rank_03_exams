/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:59:15 by emurillo          #+#    #+#             */
/*   Updated: 2025/04/22 12:18:23 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_board(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == 0)
			printf("{");
		printf("%d", board[i]);
		if (i != n - 1)
			printf(" ");
		i++;
	}
	printf("}");
	printf("\n");
}


int	check_spaces(int row, int col, int *board)
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

void	n_queens(int row, int n, int *board)
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
				n_queens(row + 1, n, board);
		}
		++col;
	}
}

int	main(int ac, char **av)
{
	int	n;

	if (ac != 2 || !av[1])
		return (printf("Error: Incorrect # of args.\n"), 1);
	n = atoi(av[1]);
	int	board[n];
	if (n < 1)
		return (printf("Error: worng number of queens.\n"), 1);
	n_queens(0, n, board);
	return (0);

}
