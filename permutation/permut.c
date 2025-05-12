/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:30:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/05/12 14:33:43 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Fonction pour échanger deux caractères
void	swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    char *new_str;
    int i = 0;

    new_str = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
    while (str[i] != '\0')
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

void    add(char ***tab, char *chaine)
{
    int len_tab = 0;

    while ((*tab)[len_tab] != NULL)
        len_tab++;
    *tab = (char **) realloc(*tab, sizeof(char *) * (len_tab + 2));
    (*tab)[len_tab] = ft_strdup(chaine);
    (*tab)[len_tab + 1] = NULL;
}

// Fonction récursive pour générer toutes les permutations
void permuter(char ***tab, char *chaine, int debut, int fin)
{
    if (debut == fin)
	{
        add(tab, chaine);
    }
	else
	{
        for (int i = debut; i <= fin; i++)
		{
            // Échanger le caractère courant avec le caractère de début
            swap(&chaine[debut], &chaine[i]);
            // Appel récursif pour les sous-chaînes restantes
            permuter(tab, chaine, debut + 1, fin);
            // Remettre la chaîne dans son état initial
            swap(&chaine[debut], &chaine[i]);
        }
    }
}

void sort_tab(char **tab)
{
    int i = 0;
    int j = 0;
    char *temp;

    while (tab[i] != NULL)
    {
        j = i + 1;
        while (tab[j] != NULL)
        {
            if (ft_strcmp(tab[i], tab[j]) > 0)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void    print_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
    {
        printf("%s\n", tab[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    char **tab;
	if (argc == 2)
	{
        tab = (char **) malloc(sizeof(char *) * 1);
        tab[0] = NULL;
		permuter(&tab, argv[1], 0, ft_strlen(argv[1]) - 1);
        sort_tab(tab);
        print_tab(tab);
	}
	return (0);
}

