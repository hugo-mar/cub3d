/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:35:26 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:35:29 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((!(c >= '0' && c <= '9')))
		return (0);
	return (1);
}

/*
int main(void)
{
	char str[] = " ";
	printf("%d", ft_isdigit(str));
}
*/