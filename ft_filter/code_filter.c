
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	filter_stdin_copy(char *stdin_copy, size_t start, size_t len)
{
	while (len > 0)
	{
		stdin_copy[start] = '*';
		len--;
		start++;
	}
}

// 1. Loop through 'stdin_copy'
// 2. If first char of filter is found in the 'stdin_copy', check if
//    the 'filter' matches all consecutives char in 'stdin_copy'
// 3. If it's a full match, replace every consecutives char by '*'
void	filter_if_match(char *filter, char *stdin_copy)
{
	size_t	i;
	size_t	j;
	size_t	match;
	size_t	filter_len;

	i = 0;
	filter_len = strlen(filter);
	while (stdin_copy[i])
	{
		if (stdin_copy[i] == filter[0])
		{
			match = i;
			j = 0;
			while (stdin_copy[match] && filter[j]
				&& stdin_copy[match] == filter[j])
			{
				match++;
				j++;
				if (match - i == filter_len)
					filter_stdin_copy(stdin_copy, i, filter_len);
			}
		}
		i++;
	}
}

void	get_stdin(char *stdin_copy)
{
	char	current_char;
	int		bytes_read;
	size_t	size;

	current_char = 0;
	bytes_read = 0;
	size = 0;
	while (1)
	{
		bytes_read = read(0, &current_char, 1);
		if (bytes_read < 0)
		{
			stdin_copy = NULL;
			return ;
		}
		stdin_copy = realloc(stdin_copy, size + 1);
		if (stdin_copy == NULL)
			return ;
		if (bytes_read == 0)
		{
			stdin_copy[size] = '\0';
			return ;
		}
		else
			stdin_copy[size] = current_char;
		size++;
	}
}

int	ft_filter(char *filter, char *stdin_copy)
{
	get_stdin(stdin_copy);
	if (stdin_copy == NULL)
		return (0);
	filter_if_match(filter, stdin_copy);
	if (stdin_copy == NULL)
		return (0);
	return (1);
}

// IMPORTANT:
// Initialize 'stdin_copy' with calloc to avoid later undefined behavior in realloc
// printf the 'stdin_copy' without '\n', it's already in the string
int	main(int ac, char **av)
{
	char	*stdin_copy;

	if (ac != 2 || av[1] == NULL)
		return (1);
	stdin_copy = calloc(sizeof(char), 1);
	if (!ft_filter(av[1], stdin_copy) || stdin_copy == NULL)
	{
		perror("Error");
		return (1);
	}
	printf("%s", stdin_copy);
	free(stdin_copy);
	return (0);
}
