/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:49:35 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 13:13:25 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	writ(char *s, int fd, int k)
{
	while (k >= 0)
	{
		write(fd, s + k, 1);
		k--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		k;
	int		temp;
	char	s[11];

	k = 0;
	if (n <= 0)
	{
		if (n < 0)
			s[0] = '-';
		if (n == 0)
			s[0] = '0';
		write(fd, s, 1);
	}
	temp = n;
	while (n != 0)
	{
		if (n >= 0)
			temp = (n % 10) + 48;
		else
			temp = ((n % 10) * -1) + 48;
		s[k++] = temp;
		n /= 10;
	}
	writ(s, fd, (k - 1));
}

/*
int main(void)
{
	int	n = 0;
	ft_putnbr_fd(n, 1);
}
*/