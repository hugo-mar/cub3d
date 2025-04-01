/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:35:51 by divalent          #+#    #+#             */
/*   Updated: 2025/03/25 18:14:51 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	s = (void *) malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size * nmemb);
	return (s);
}

/*
int	main(void)
{
	printf("%p", ft_calloc(5, 5));
}
*/