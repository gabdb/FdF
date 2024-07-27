/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_and_crasse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:27:09 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/27 17:03:17 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_line_exit(char *line)
{
	free(line);
	exit(EXIT_FAILURE);
}

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