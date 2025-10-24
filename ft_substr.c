/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:12:54 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/24 11:44:37 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static void	fill_array(char *result, const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] && i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		ptr = malloc(1);
		*ptr = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s) - start)
		ptr = malloc((ft_strlen(s) - start) + 1);
	else
		ptr = (char *)malloc(len + 1);
	if (!ptr || !s)
		return (NULL);
	fill_array(ptr, &s[start], len);
	return (ptr);
}
