/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:40:56 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/20 14:28:23 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	move_func(unsigned char *d_ptr, unsigned char *s_ptr, size_t n)
{
	size_t	i;

	if (d_ptr > s_ptr)
	{
		i = n ;
		while (i)
		{
			d_ptr[i - 1] = s_ptr[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d_ptr[i] = s_ptr[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;

	if (!dest || !src)
		return (NULL);
	d_ptr = (unsigned char *)dest;
	s_ptr = (unsigned char *)src;
	move_func(d_ptr, s_ptr, n);
	return (dest);
}
