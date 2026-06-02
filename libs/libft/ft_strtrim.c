/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 08:36:46 by daherman          #+#    #+#             */
/*   Updated: 2026/04/28 09:12:53 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	start_end(const char *s1, const char *set, int *start, int *end)
{
	*start = 0;
	while (s1[*start] && set_check(s1[*start], set))
		(*start)++;
	*end = ft_strlen(s1) - 1;
	while (*end >= *start && set_check(s1[*end], set))
		(*end)--;
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		len;
	int		i;
	char	*new_s;

	if (!s1 || !set)
		return (NULL);
	start_end(s1, set, &start, &end);
	len = end - start + 1;
	if (len < 0)
		len = 0;
	new_s = malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = s1[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
