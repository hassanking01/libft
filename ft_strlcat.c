/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:55:03 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/19 17:16:38 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	if (!size || i >= size)
	{
		return (ft_strlen(src) + size);
	}
	j = 0;
	while (j < size - i - 1 && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	j = ft_strlen(src);
	return (j + i);
}
