/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:35:11 by divalent          #+#    #+#             */
/*   Updated: 2025/03/27 15:04:04 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ff15(int n)
{
	int		t;

	t = 0;
	if (n <= 0)
		t++;
	while (n != 0)
	{
		n /= 10;
		t++;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	int		k;
	int		temp;
	char	*s;

	k = ff15(n);
	s = (char *) malloc(sizeof(char) * (k + 1));
	if (s == NULL)
		return (NULL);
	s[k] = '\0';
	if (n < 0)
		s[0] = '-';
	temp = n;
	if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		if (n >= 0)
			temp = (n % 10) + 48;
		else
			temp = ((n % 10) * -1) + 48;
		s[--k] = temp;
		n /= 10;
	}
	return (s);
}

/*
int main(void)
{
	int n = -623;
	printf("%s", ft_itoa(n));
}
*/