/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:59:43 by divalent          #+#    #+#             */
/*   Updated: 2023/10/24 11:52:57 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*as;

	as = malloc((ft_strlen(s) + 1));
	if (as == NULL)
		return (NULL);
	n = 0;
	while (s[n])
	{
		as[n] = f(n, s[n]);
		n++;
	}
	as[n] = '\0';
	return (as);
}

/*
int main(void)
{
	unsigned int n = 0;
	char s[] = "O33la 6";
	char *as = ft_strmapi(s, f);
	printf("%s", as);
}
*/