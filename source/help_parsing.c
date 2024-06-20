/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:35:23 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/20 15:36:42 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int index_base(char c, char *base)
{
    int i;
	
	i = 0;
    while (base[i])
    {
        if (c == base[i] || (c - 32) == base[i])
            return (i);
        i++;
    }
	return (-1); //gros probleme dans ce cas-la
}

int	my_atoi_base(char *str)
{
	char	*base;
	int		i;
	int		index;
	int		result;

	base = "0123456789ABCDEF";
	result = 0;
	i = 0;
	while (str[i])
	{
		index = index_base(str[i], base);
		result = result * 16 + index;
		i++;
	}
	return (result);
}
