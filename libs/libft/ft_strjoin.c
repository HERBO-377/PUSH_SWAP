/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:43:52 by daherman          #+#    #+#             */
/*   Updated: 2026/04/28 09:33:18 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*new_word(char *new_word, const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		new_word[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_word[i + j] = s2[j];
		j++;
	}
	new_word[i + j] = '\0';
	return (new_word);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_s;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = malloc((s2_len + s1_len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	new_word(new_s, s1, s2);
	return (new_s);
}
