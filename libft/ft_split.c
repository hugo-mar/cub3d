/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:53:39 by divalent          #+#    #+#             */
/*   Updated: 2023/10/23 12:53:41 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countww(const char *s, char c)
{
	int		n;
	int		d;

	n = 0;
	d = 0;
	while (s[n])
	{
		while (s[n] == c)
			n++;
		if (s[n])
			d++;
		while (s[n] != c && s[n])
			n++;
	}
	return (d);
}

static void	cleanww(char **as, size_t len)
{
	size_t	n;

	n = 0;
	while (n <= len)
	{
		free(as[n]);
		n++;
	}
	free(as);
}

static char	**sepa(const char *s, int n, int b, char c)
{
	int		d;
	char	**as;

	d = 0;
	as = (char **) malloc((countww(s, c) + 1) * sizeof(char *));
	if (as == NULL)
		return (NULL);
	as[countww(s, c)] = NULL;
	while (d < countww(s, c))
	{
		while (s[n] == c)
			n++;
		b = n;
		while (s[n] != c && s[n])
			n++;
		as[d] = ft_substr(s, b, (n - b));
		if (as[d] == NULL)
		{
			cleanww(as, d);
			return (NULL);
		}
		d++;
	}
	return (as);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	int		b;
	char	**as;

	b = 0;
	n = 0;
	if (!s)
		return (NULL);
	as = sepa(s, n, b, c);
	return (as);
}

/*
int main(void)
{
	char *s = ". Ola....amgio.";
	char **as;
	char c = '.';
	int i = 0;
	
	as = ft_split(s, c);
	while(as[i] && as != NULL)
	{
		printf("%s\n", as[i]);
		i++;
	}
}
*/