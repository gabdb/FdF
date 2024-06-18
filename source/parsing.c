/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:25:35 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/18 16:22:56 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	if (i > 1 && s[i - 1] == '\n' && s[i - 2] == ' ')
		count--;
	return (count);
}

int	check_map(int ac, char **argv)
{
	int		fd;
	int		len;
	int		count_line;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
		return (0);
	line = get_next_line(fd);
	if (!line || *line == '\0')
		return (printf("empty map"), 0);
	len = ft_count_words(line, ' ');
	count_line = 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
		{
			count_line++;
			if (ft_count_words(line, ' ') != len)
				return (printf("map not square"), 0);
		}
	}
	return (free(line), count_line * len);
}

int main(int ac, char **av)
{
	int result = check_map(ac, av);

	printf("test result: %d", result);

	return 0;
}