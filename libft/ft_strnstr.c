/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:02:18 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 13:02:57 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	i;
	char	*s1;

	s1 = (char *) big;
	i = 0;
	n = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (s1[n] && n <= len)
	{
		while (s1[n + i] == little[i] && n + i < len && s1[n + i])
			i++;
		if (little[i] == '\0')
			return (s1 + n);
		n++;
		i = 0;
	}
	return (0);
}

/*
int main(void)
{
	char str[] = "Ola meu bom amigo";
	char find[] = "bom";
	printf("%s", ft_strnstr(str, str, 18));
	return(0);
}
*/