/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:06:23 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/23 17:41:47 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		del(ptr->content);
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}
