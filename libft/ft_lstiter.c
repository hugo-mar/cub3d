/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:34:39 by divalent          #+#    #+#             */
/*   Updated: 2023/10/24 11:52:59 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
int main(void)
{
	t_list *node1 = ft_lstnew("ola");
	t_list *node2 = ft_lstnew("adeus");
	t_list **lst = &node1;
	ft_lstadd_front(lst, node2);
	ft_lstiter(lst, f);
}
*/