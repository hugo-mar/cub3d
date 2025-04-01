/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:59 by divalent          #+#    #+#             */
/*   Updated: 2023/11/15 11:49:59 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = (t_list *) malloc(sizeof(t_list));
	if (a == NULL)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}

/*
int main(void)
{
	void *content = "Ola";
	t_list *node = ft_lstnew(content);
	printf("%s", (char *)node->content);
}
*/
