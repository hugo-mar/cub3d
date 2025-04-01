/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:57:35 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:58:04 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	while (n + 1 < size && src[n])
	{
		dst[n] = src[n];
		n++;
	}
	if (size > 0)
		dst[n] = '\0';
	while (src[n])
		n++;
	return (n);
}

/*
int main(void)
{
	char dest[30];
	char src[] = ", es bue fixe";
	printf("%zu\n", ft_strlcpy(dest, src, 0));
	printf("%s\n", dest);
}
*/