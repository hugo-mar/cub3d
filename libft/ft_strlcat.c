/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:56:56 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:57:24 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		i;
	size_t		k;

	n = 0;
	i = 0;
	k = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	while (src[n] && (n + i + 1) < size)
	{
		dst[i + n] = src[n];
		n++;
	}
	if (i < size)
		dst[i + n] = '\0';
	return (k);
}

/*
int main(void)
{
	char dest[14] = "a";
	char src[] = "lorem ipsum dolor sit amet";
	printf("%zu\n", ft_strlcat(dest, src, 16));
	printf("%s", dest);
}
*/