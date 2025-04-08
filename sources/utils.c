/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:35 by divalent          #+#    #+#             */
/*   Updated: 2025/04/08 17:26:00 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_int_array(int **arr, int max)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < max)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	fill(char **tab, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (!tab[y] || !tab[y][x])
		return ;
	if (tab[y][x] == 'F' || tab[y][x] == '1')
		return ;
	tab[y][x] = 'F';
	fill(tab, x - 1, y);
	fill(tab, x + 1, y);
	fill(tab, x, y - 1);
	fill(tab, x, y + 1);
}

char	**copy_array(char **arr)
{
	char	**temp;
	int		k;

	k = 0;
	if (!arr)
		return (NULL);
	while (arr[k])
		k++;
	temp = ft_calloc(k + 1, sizeof(char *));
	k = 0;
	while (arr[k])
	{
		temp[k] = ft_strdup(arr[k]);
		k++;
	}
	return (temp);
}
