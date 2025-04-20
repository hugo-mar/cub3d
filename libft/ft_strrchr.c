/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:03:05 by divalent          #+#    #+#             */
/*   Updated: 2023/11/08 14:55:35 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	while (n >= 0)
	{
		if (s[n] == (char) c)
			return ((char *)(s + n));
		n--;
	}
	return (NULL);
}

/*
int main(void)
{
	char s[] = "Ola";
	int c = 0;
	printf("%s", ft_strrchr(s, c));
}
*/