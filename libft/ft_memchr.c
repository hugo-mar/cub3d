/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:39:39 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:45:17 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str;

	str = (const unsigned char *) s;
	while (n > 0)
	{
		if (*str == (unsigned char ) c)
			return ((unsigned char *)(str));
		n--;
		str++;
	}
	return (NULL);
}

/*
int main(void)
{
	char s[] = "Ola amigo";
	int c = 122;
	printf("%p\n", ft_memchr(s, c, sizeof(s)));
}
*/