/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:35 by divalent          #+#    #+#             */
/*   Updated: 2025/04/23 16:04:50 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_all_here(t_mapt *maps)
{
	if (maps->no && maps->so && maps->ea && maps->we
		&& maps->floor[2] >= 0 && maps->ceiling[2] >= 0
		&& maps->floor[1] >= 0 && maps->ceiling[1] >= 0
		&& maps->floor[0] >= 0 && maps->ceiling[0] >= 0)
	{
		return (1);
	}
	return (0);
}

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
