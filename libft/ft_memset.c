/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:44 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:48:46 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		k;
	char		*s1;

	s1 = (char *) s;
	k = 0;
	while (k < n)
	{
		s1[k] = c;
		k++;
	}
	return ((char *) s);
}

/*
int main(void)
{
	char s[] = "Ola meu amigo";
	int c = 122;
	printf("%p\n", ft_memset(s, c, sizeof(s)));
	printf("%s", s);
}
*/