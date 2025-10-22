/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:18:31 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/22 12:09:13 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	is_from_set(char const *set, char check)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == check)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strndup(char const *s1, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(n + 1);
	while (i < n)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	s_len;

	s_len = ft_strlen(s1);
	j = 0;
	if (!s1 || !set)
		return (NULL);
	j = 0;
	while (j < s_len && is_from_set(set, s1[j]))
		j++;
	i = s_len;
	while (i > j && is_from_set(set, s1[i -1]))
		i--;
	ptr = ft_strndup(&s1[j], i - j);
	return (ptr);
}
