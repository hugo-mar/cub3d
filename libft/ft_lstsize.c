/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:38:34 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:39:06 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;

	n = 0;
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

/*
int main(void)
{
	t_list *node1 = ft_lstnew("as");
	t_list *node2 = ft_lstnew("a");
	t_list *node3 = ft_lstnew("b");
	ft_lstadd_front(&node3, node2);
	ft_lstadd_front(&node2, node1);
	printf("%d", ft_lstsize(node1));
}
*/