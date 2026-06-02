/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:42:40 by daherman          #+#    #+#             */
/*   Updated: 2026/05/04 08:38:48 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_all(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static char	**create_word(char **arr, const char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = word_len(&s[i], c);
			arr[j] = ft_substr(s, i, len);
			if (!arr[j])
				return (free_all(arr, j), NULL);
			i += len;
			j++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	return (create_word(arr, s, c));
}
