/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:03:36 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 13:04:18 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		n;
	int		b;

	b = ft_strlen(s1) - 1;
	n = 0;
	while (s1[n])
	{
		if (ft_strchr(set, s1[n]) == NULL)
			break ;
		n++;
	}
	while (b > n)
	{
		if (ft_strchr(set, s1[b]) == NULL)
			break ;
		b--;
	}
	s2 = ft_substr(s1, n, (b + 1 - n));
	return (s2);
}

/*
int main(void)
{
	char s1[] = "ola meu amigo ola";
	char set[] = "";

	printf("%s", ft_strtrim(s1, set));
}
*/