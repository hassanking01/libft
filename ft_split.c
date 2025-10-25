/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:55:22 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/25 13:59:31 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static char	*ft_strndup(const char *s, size_t	n)
{
	size_t	i;
	char	*ptr;

	ptr = malloc(n + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static size_t	count_words(const char *s, char c)
{
	int		is_added;
	size_t	i;
	size_t	count;

	if (!c)
		return (1);
	count = 0;
	i = 0;
	is_added = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!is_added)
			{
				count++;
				is_added = 1;
			}
		}
		else
			is_added = 0;
		i++;
	}
	return (count);
}

static int	free_array(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	return (0);
}

static int	fill_array(char **ptr, const char *s, char c)
{
	size_t	i;
	size_t	ptr_i;
	size_t	count_n;

	ptr_i = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_n = 0;
			while ((s[i + count_n] != c) && s[i + count_n])
				count_n++;
			ptr[ptr_i] = ft_strndup(&s[i], count_n);
			if (!ptr[ptr_i])
				return (free_array(ptr));
			i += count_n;
			ptr_i++;
		}
		else
			i++;
	}
	ptr[ptr_i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;

	if (!(*s))
	{
		ptr = malloc(sizeof(char *));
		ptr[0] = NULL;
		return (ptr);
	}
	count = count_words(s, c);
	ptr = malloc((count + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	if (!fill_array(ptr, s, c))
		return (NULL);
	return (ptr);
}
