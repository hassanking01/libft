/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:18:31 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/19 18:01:31 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dup;
	char	*ptr;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen(s1) - 1;
	dup = ft_strdup(s1);
	while (is_from_set(set, dup[i]))
		dup[i--] = '\0';
	i = 0;
	while (is_from_set(set, dup[i]))
		i++;
	ptr = ft_strdup(&dup[i]);
	return (ptr);
}
