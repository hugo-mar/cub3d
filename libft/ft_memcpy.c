/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:27 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 13:43:32 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			k;
	unsigned char	*s2;
	unsigned char	*s1;

	s1 = (unsigned char *) src;
	s2 = (unsigned char *) dest;
	k = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (k < n)
	{
		s2[k] = s1[k];
		k++;
	}
	return ((unsigned char *) dest);
}

/*
int main(void)
{
	char dest[30];
	char src[] = "zy^@xw^@vu^@^@tjjjjjjjjjjjjjjjjjjj";
	printf("%s\n", dest);
	printf("%p\n", ft_memcpy(dest, src, 13));
	printf("%s\n", dest);
	printf("%p\n", memcpy(dest, src, 13));
	printf("%s\n", dest);
}
*/