/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 00:43:15 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/19 16:34:11 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	get_pow_count(int *count, long int m)
{
	int	pow;

	pow = 1;
	while (m / pow >= 10)
	{
		*count = *count + 1;
		pow *= 10;
	}
	return (pow);
}

static void	fill_array(char *ptr, int n, int pow)
{
	int			i;
	long int	m;

	m = (long int)n;
	i = 0;
	if (n < 0)
	{
		ptr[i] = '-';
		i++;
		m = -m;
	}
	while (pow > 0)
	{
		ptr[i] = (char)((m / pow) + '0');
		m %= pow;
		pow /= 10;
		i++;
	}
	ptr[i] = '\0';
}

char	*ft_itoa(int n)
{
	long int	m;
	int			count;
	int			pow;
	char		*ptr;

	count = 1;
	m = (long int)n;
	if (m < 0)
	{
		count++;
		m = -m;
	}
	pow = get_pow_count(&count, m);
	ptr = malloc(count + 1);
	if (!ptr)
		return (NULL);
	fill_array(ptr, n, pow);
	return (ptr);
}
