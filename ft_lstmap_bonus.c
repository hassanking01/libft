/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:23:40 by hahchtar          #+#    #+#             */
/*   Updated: 2025/10/23 17:53:50 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*newlist;
	void	*newcont;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	ptr = lst;
	newlist = NULL;
	while (ptr)
	{
		newcont = f(ptr->content);
		if (!newcont)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newnode = ft_lstnew(newcont);
		ft_lstadd_back(&newlist, newnode);
		ptr = ptr->next;
	}
	return (newlist);
}
