/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:55:22 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/21 16:56:44 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t	n)
{
	size_t	i;
	char	*ptr;

	ptr = malloc(n + 1);
	i = 0;
	while (s[i] && i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	count_words(const char *s, char c)
{
	int		is_added;
	size_t	i;
	size_t	count;

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

void	fill_array(char **ptr, const char *s, char c)
{
	size_t	i;
	size_t	ptr_i;
	size_t	count_n;

	count_n = 0;
	ptr_i = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_n = 0;
			while (s[i + count_n] != c)
			{
				count_n++;
			}
			ptr[ptr_i++] = ft_strndup(&s[i], count_n);
			i += count_n;
		}
		i++;
	}
	ptr[ptr_i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	count;

	i = 0;
	count = count_words(s, c);
	ptr = malloc((count + 1) * sizeof(char *));
	fill_array(ptr, s, c);
	return (ptr);
}
