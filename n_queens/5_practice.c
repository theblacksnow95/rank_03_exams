/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_practice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:54:53 by emurillo          #+#    #+#             */
/*   Updated: 2025/04/26 19:09:00 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_board(int * board, int q)
{
	int	i;

	i = 0;
	while (i < q)
	{
		printf("%d", board[i]);
		if (i != q - 1)
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
		if (board[i] == col
		|| board[i] == col - (row - i)
		|| board[i] == col + (row - i))
			return (0);
		i++;
	}
	return (1);
}

void	n_queens(int row, int q, int *board)
{
	int	col;

	col = 0;
	while (col < q)
	{
		if (check_spaces(row, col, board))
		{
			board[row] = col;
			if (row == q - 1)
				print_board(board, q);
			else
				n_queens(row + 1, q, board);
		}
		++col;
	}
}

int	main(int ac, char **av)
{
	int	q;

	if (ac != 2 || !av[1])
		return (printf("Error: incorrect num of args.\n"), 1);
	q = atoi(av[1]);
	if (q < 1)
		return (printf("Error: incorrect num of queens.\n"), 1);
	int	board[q];
	n_queens(0, q, board);
	return (0);
}
