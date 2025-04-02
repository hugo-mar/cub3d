/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:34:57 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:35:01 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int main(void)
{
	void *content = "Ola";
	t_list *node = ft_lstnew("abc");
	t_list *new = ft_lstnew(content);
	
	ft_lstadd_front(&new, node);
	printf("%s\n", (char *) node->content);
	printf("%s", (char *) node->next->content);
}
*/