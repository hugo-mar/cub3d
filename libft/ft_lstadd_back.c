/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:34:50 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:35:07 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ff;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ff = ft_lstlast(*lst);
	ff->next = new;
}

/*
int main(void)
{
	t_list *node = ft_lstnew("abc");
	t_list *new = ft_lstnew("def");
	
	ft_lstadd_back(&node, new);
	printf("%s\n", (char *) node->next->content);
}
*/