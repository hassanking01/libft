/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:13:13 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/20 13:55:03 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	get_pow(long int m)
{
	int	pow;

	pow = 1;
	while (m / pow >= 10)
		pow *= 10;
	return (pow);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	m;
	int			pow;
	char		digit;

	m = (long int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		m = -m;
	}
	pow = get_pow(m);
	while (pow > 0)
	{
		digit = (char)(m / pow + '0');
		write(fd, &digit, 1);
		m %= pow;
		pow /= 10;
	}
}
