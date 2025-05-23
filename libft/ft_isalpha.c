/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:35:40 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:35:42 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((!(c >= 'a' && c <= 'z')) && (!(c >= 'A' && c <= 'Z')))
		return (0);
	return (1);
}

/*
int main(void)
{
	char str[] = "1";
	printf("%d", ft_isalpha(str));
}
*/