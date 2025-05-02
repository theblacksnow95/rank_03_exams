/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:23:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/04/16 11:31:48 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void replace_filter(char *copy_stdin, size_t start, size_t len)
{
	while (len--)
	{
		copy_stdin[start++] = '*';
	}
}

void	filter_if_match(char *filter, char *copy_stdin)
{
	size_t	i;
	size_t	j;
	size_t	match;
	size_t	len;

	i = 0;
	len = strlen(filter);
	while (copy_stdin[i])
	{
		if (copy_stdin[i] == filter[0])
		{
			match = i;
			j = 0;
			while (copy_stdin[match] && filter[j]
				&& copy_stdin[match] == filter[j])
			{
				match++;
				j++;
				if (j == len)
					replace_filter(copy_stdin, i, len);
			}
		}
		i++;
	}
}


char	*get_stdin(void)
{
	char	*copy_stdin;
	char	*tmp;
	char	current_char;
	size_t	bytes_to_read;
	size_t	size;

	copy_stdin = NULL;
	tmp = NULL;
	size = 0;
	bytes_to_read = 1;
	while (bytes_to_read > 0)
	{
		bytes_to_read = read(STDIN_FILENO, &current_char, 1);
		if (bytes_to_read > 0)
		{
			tmp = realloc(copy_stdin, size + 2);
			if (!tmp)
			{
				free(copy_stdin);
				return (NULL);
			}
			copy_stdin = tmp;
			copy_stdin[size] = current_char;
			size++;
		}
	}
	if (copy_stdin)
		copy_stdin[size] = '\0';
	return (copy_stdin);
}

int	filter(char *filter, char **copy_stdin)
{
	*copy_stdin = get_stdin();
	if (copy_stdin == NULL)
		return (0);
	filter_if_match(filter, *copy_stdin);
	return (1);
}


int	main(int ac, char **av)
{
	char *copy_stdin;

	if (ac != 2 || av[1] == NULL)
		return (EXIT_FAILURE);
	copy_stdin = NULL;
	if (!filter(av[1], &copy_stdin) || !copy_stdin)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	printf("%s", copy_stdin);
	free(copy_stdin);
	return (EXIT_SUCCESS);
}
