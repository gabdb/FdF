/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:25:35 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/18 18:35:41 by gnyssens         ###   ########.fr       */
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
		return (printf("empty map !\n"), 0);
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
				return (printf("map not square !\n"), 0);
		}
	}
	return (free(line), count_line * len);
}

t_point	*parsing(char *map, int total_length, int one_line_len) //total_length cest le nombre de points sur la map.
{
	char	**real_line;
	t_point	*result;
	char	*line;
	int		fd;
	int		i;
	int		j;

	result = (t_point *)malloc(sizeof(t_point) * (total_length + 1));
	if (!result)
		exit(EXIT_FAILURE);
	fd = open(map, O_RDONLY);
	if (-1 == fd)
		return (NULL); //ici faudra free result et exit
	i = 0;
	while ((i * one_line_len) < total_length)
	{
		line = get_next_line(fd);
		real_line = ft_split(line, ' ');
		if (!real_line)
			return (NULL); //ici faudra free result et exit
		j = -1;
		while (real_line[++j] != NULL)
		{
			(result[(i * one_line_len) + j]).x = j;
			(result[(i * one_line_len) + j]).y = i;
			(result[(i * one_line_len) + j]).z = ft_atoi(real_line[j]);
			(result[(i * one_line_len) + j]).color = 0xFF00FF;
		}
		free(real_line);
		free(line);
		i++;
	}
	result[total_length].x = -1;
	result[total_length].y = -1;
	result[total_length].z = -1;

	return (result);
}

int main(int ac, char **av)
{
	int result = check_map(ac, av);

	t_point *test = parsing(av[1], result, 19);

	int i = -1;
	while (test[++i].x != -1)
		printf("x = %d, y = %d, z = %d\n", test[i].x, test[i].y, test[i].z);
	free(test);

	return 0;
}
