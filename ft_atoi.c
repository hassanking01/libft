/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:46:37 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/23 14:27:02 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	skip_isspace(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long int	i;
	long int	num;
	int			sign;

	sign = 1;
	i = skip_isspace(nptr);
	if (!ft_isdigit((int)nptr[i]) && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	num = 0;
	while (ft_isdigit((int)nptr[i]))
	{
		num *= 10;
		num += (int)nptr[i] - '0';
		i++;
	}
	return ((int)(num * sign));
}
