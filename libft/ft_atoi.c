/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:02:55 by divalent          #+#    #+#             */
/*   Updated: 2024/05/28 16:09:58 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		n;
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	n = 0;
	while ((nptr[n] == ' ') || (nptr[n] >= 9 && nptr[n] <= 13))
		n++;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
			sign = -sign;
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		result = (result * 10) + (nptr[n] - '0');
		n++;
	}
	return (result * sign);
}

/*
int main(void)
{
	char str[] = "	  -123 4";
	printf("%d\n", ft_atoi(str));
	return (0);
}
*/