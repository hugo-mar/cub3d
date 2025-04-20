/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:37 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 16:03:35 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *) dest;
	s2 = (char *) src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		return ((ft_memcpy(dest, src, n)));
	while (n--)
		s1[n] = s2[n];
	return (dest);
}

/*
int main(void)
{
	char dest[20];
	char src[] = "Copia esta";
	printf("%p\n", ft_memmove(dest, src, 10));
	printf("%p\n", memmove(dest, src, 10));
	printf("%s", dest);
}
*/