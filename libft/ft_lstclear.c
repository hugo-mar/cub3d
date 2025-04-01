/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:07:08 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:32:48 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		(*del)(node->content);
		free(node);
	}
}

/*
int main(void)
{
	t_list *node1 = ft_lstnew("ola");
	t_list *node2 = ft_lstnew("adeus");
	t_list **lst = &node1;
	ft_lstadd_front(lst, node2);
	ft_lstclear(lst, del);
}
*/