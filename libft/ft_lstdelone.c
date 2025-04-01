/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:10:47 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:33:05 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/*
int main(void)
{
	t_list *node1 = ft_lstnew("123");
	t_list *node2 = ft_lstnew("456");
	printf("%s\n", (char *) node1->next->content);
}
*/