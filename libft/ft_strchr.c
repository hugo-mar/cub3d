/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:53:49 by divalent          #+#    #+#             */
/*   Updated: 2023/10/25 12:32:41 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		n;

	n = 0;
	while (s[n])
	{
		if (s[n] == (char)c)
			return ((char *)(s + n));
		n++;
	}
	if ((char)c == 0)
		return ((char *)(s + n));
	return (NULL);
}

/*
int main(void)
{
	char s[] = "teste";
	int c = 357;
	printf("%s", ft_strchr(s, c));
}
*/