/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:35:56 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:35:58 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n > 0)
	{
		str[n - 1] = 0;
		n--;
	}
}

/*
int main(void)
{
	char s[] = "Ola amigo";
	ft_bzero(s, sizeof(s));
	printf("%s", s);
}
*/