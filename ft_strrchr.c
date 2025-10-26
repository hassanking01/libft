/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:30:20 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/26 21:09:47 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*old;
	const char	*ptr;

	old = NULL;
	ptr = s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			old = ptr;
		ptr++;
	}
	if (c == 0)
	{
		return ((char *)ptr);
	}
	return ((char *)old);
}
