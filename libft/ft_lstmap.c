/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:36:55 by divalent          #+#    #+#             */
/*   Updated: 2023/10/24 12:01:59 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*a;

	if (lst == NULL)
		return (NULL);
	lst1 = NULL;
	while (lst)
	{
		a = ft_lstnew((*f)(lst->content));
		if (a == NULL)
		{
			ft_lstclear(&lst1, (*del));
			return (lst1);
		}
		ft_lstadd_back(&lst1, a);
		lst = lst->next;
	}
	return (lst1);
}

/*
void	del(void *garen)
{
	garen = NULL;
}

void	*f(void *a)
{
	int		n;
	char 	*c;
	char	*str;

	c = (char *) a;
	str = ft_strdup(c);
	n = 0;
	while(str[n])
	{
		if (str[n] >= 'a' && str[n] <= 'z')
			str[n] = str[n] - 32;
		n++;
	}
	return (str);
}

int main(void)
{
	t_list *lst;
	t_list *lst1;

	lst = ft_lstnew("fF15");
	lst1 = ft_lstnew("fF16");
	ft_lstadd_back(&lst1, lst);
	lst = ft_lstmap(lst, f, del);
	printf("%s", (char *) lst->content);
}
*/