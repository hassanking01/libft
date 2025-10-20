/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:02:20 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/19 16:38:47 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	if (fd < 0)
		return ;
	ptr = s;
	while (*ptr)
	{
		write(fd, ptr++, len);
	}
}
