/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:56:49 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:56:51 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *) malloc(len1 + len2 + 1);
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, len1 + 1);
	ft_strlcpy(s3 + len1, s2, len2 + 1);
	return (s3);
}

/*
int main(void)
{
	char s1[] = "Ola";
	char s2[] = " amigo";
	printf("%s", ft_strjoin(s1, s2));
}
*/