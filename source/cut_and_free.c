/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:27:09 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/30 17:52:32 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_line_exit(char *line)
{
	free(line);
	write(1, "map not rectangular !\n", 22);
	exit(EXIT_FAILURE);
}

void	free_result_exit(t_point *point)
{
	free(point);
	exit(EXIT_FAILURE);
}

void	free_line_result_exit(t_point *point, char *line)
{
	free(line);
	free(point);
	exit(EXIT_FAILURE);
}

void	free_double(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
	}
	free(line[i]);
	free(line);
}
