/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:55:25 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:55:44 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		n;
	char	*s1;

	n = 0;
	s1 = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	while (s[n])
	{
		s1[n] = s[n];
		n++;
	}
	s1[n] = '\0';
	return ((char *) s1);
}

/*
int main(void)
{
	char s[] = "Ola meu amigo";
	printf("%s", ft_strdup(s));
}
*/