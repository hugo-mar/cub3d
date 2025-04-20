/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:55:56 by divalent          #+#    #+#             */
/*   Updated: 2023/10/24 11:53:07 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	n;

	n = 0;
	while (s[n])
	{
		f(n, s + n);
		n++;
	}
	s[n] = '\0';
}

/*
int main(void)
{
	unsigned int n = 0;
	char s[] = "O33la 6";
	char *as = ft_striteri(s, f);
	printf("%s", as);
}
*/