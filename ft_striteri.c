/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:39:53 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/21 18:07:15 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char			*ptr;
	unsigned int	i;

	ptr = s;
	i = 0;
	if (!ptr || !f)
		return ;
	while (*ptr)
		f(i++, ptr++);
}
