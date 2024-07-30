/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:06:40 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/30 18:04:39 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*protected_malloc(int count_line, int len)
{
	int	*result;

	result = (int *)malloc(sizeof(int) * 2);
	if (!result)
		exit(EXIT_FAILURE);
	*result = count_line;
	*(result + 1) = len;
	return (result);
}

t_point	*special_malloc(int length)
{
	t_point	*result;

	result = (t_point *)malloc(sizeof(t_point) * (length + 1));
	if (!result)
		exit(EXIT_FAILURE);
	return (result);
}

int	safe_open(char *map, t_point *result)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		free_result_exit(result);
	return (fd);
}

void	mega_free(char *line, char **real_line)
{
	free(real_line);
	free(line);
}
