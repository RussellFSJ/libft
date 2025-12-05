/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:24:52 by rfoo              #+#    #+#             */
/*   Updated: 2025/12/05 14:57:59 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static void	free_arr(char **arr);
static void	fill_arr(char **arr, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char		**arr;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fill_arr(arr, s, c);
	return (arr);
}

static int	count_words(char const *s, char c)
{
	size_t	count;
	int		new_word;

	count = 0;
	new_word = 1;
	while (*s)
	{
		if (*s != c && new_word)
		{
			new_word = 0;
			count++;
		}
		else if (*s == c)
			new_word = 1;
		s++;
	}
	return (count);
}

static void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	fill_arr(char **arr, char const *s, char c)
{
	char const	*start;
	char const	*end;
	size_t		i;

	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = s;
			end = ft_strchr(s, c);
			if (!end)
				end = s + ft_strlen(s);
			arr[i] = ft_substr(start, 0, end - start);
			if (!arr[i])
			{
				free_arr(arr);
			}
			s = end;
			i++;
		}
	}
	arr[i] = NULL;
}
