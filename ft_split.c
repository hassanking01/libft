/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:55:22 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/19 16:39:08 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	count_words(char *s, size_t len)
{
	size_t	i;
	int		is_counted;
	size_t	count;

	count = 0;
	is_counted = 0;
	i = 0;
	while (!s[i])
		i++;
	while (i < len)
	{
		if (!s[i])
		{
			if (!is_counted)
			{
				count++;
				is_counted = 1;
			}
		}
		else
			is_counted = 0;
		i++;
	}
	return (count);
}

static void	null_check(char *dup, char c)
{
	size_t	i;

	i = 0;
	while (dup[i])
	{
		if (dup[i] == c)
			dup[i] = '\0';
		i++;
	}
}

static void	fill_array(char **ptr, char *dup, size_t count)
{
	size_t	i;

	i = 0;
	while (!(*dup))
		dup++;
	while (i < count)
	{
		if (*dup)
		{
			i++;
			*ptr++ = ft_strdup(dup);
			while (*dup)
				dup++;
		}
		dup++;
	}
	*ptr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*dup;
	size_t	count;

	dup = ft_strdup(s);
	null_check(dup, c);
	count = count_words(dup, ft_strlen(s)) + 1;
	ptr = malloc(count * sizeof(char *));
	if (!ptr)
		return (NULL);
	fill_array(ptr, dup, count - 1);
	return (ptr);
}
