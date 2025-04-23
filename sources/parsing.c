/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:29 by divalent          #+#    #+#             */
/*   Updated: 2025/04/23 16:11:04 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing_start(int argc, char **argv, t_mapt *maps)
{
	if (argc < 2 || argc > 2)
		return (1);
	maps_init(maps);
	if (check_map(maps, argv[1]) == 1)
	{
		ft_printf("Error\n Invalid Map (for some reason)\n");
		maps_cleaner(maps);
		return (1);
	}
	return (0);
}
