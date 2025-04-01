/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:04:59 by divalent          #+#    #+#             */
/*   Updated: 2024/03/12 14:51:48 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	a;

	a = ft_strlen(s);
	if (start >= a)
		len = 0;
	else if (len + start > a)
		len = a - start;
	s1 = (char *) malloc((len + 1) * sizeof(char));
	if (len == 0)
	{
		s1[0] = '\0';
		return (s1);
	}
	if (s1 != NULL)
	{
		ft_strlcpy(s1, &s[start], (len + 1));
		return (s1);
	}
	return (NULL);
}

/*
int main(void)
{
	char s[] = "Hola";
	printf("%s", ft_substr(s, 4294967295, 0));
}
*/