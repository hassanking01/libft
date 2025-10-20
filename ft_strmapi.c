/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 01:24:54 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/20 13:59:38 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*ptr;

	len = ft_strlen(s);
	ptr = ft_strdup(s);
	i = 0;
	while (i < len)
	{
		ptr[i] = f(i, ptr[i]);
		i++;
	}
	return (ptr);
}
