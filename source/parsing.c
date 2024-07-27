/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:25:35 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/27 22:59:22 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_words(char *s, char c)
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

void	handle_color(t_point *point, char *map_point)
{
	int		i;

	i = 0;
	while (map_point[i] && map_point[i] != ',')
		i++;
	if (map_point[i] != ',')
	{
		(*point).color = 0xFFFFFF; //set to white if no color specified
		return ;
	}
	i += 3; //pr passer de `,` à `F` direct sans `0x`
	(*point).color = my_atoi_base(map_point + i);
}

int	*check_map(int ac, char **argv)
{
	t_map	m;

	if (ac != 2)
		exit(EXIT_FAILURE);
	m.fd = open(argv[1], O_RDONLY);
	if (-1 == m.fd)
		exit(EXIT_FAILURE);
	m.line = get_next_line(m.fd);
	if (!m.line || *m.line == '\0') //si *line == '\0' faut free ?
		return (printf("empty map !\n"), NULL);
	m.len = ft_count_words(m.line, ' ');
	m.count_line = 1;
	while (m.line != NULL)
	{
		free(m.line);
		m.line = get_next_line(m.fd);
		if (m.line != NULL)
		{
			m.count_line++;
			if (ft_count_words(m.line, ' ') != m.len)
				free_line_exit(m.line);
		}
	}
	m.result = protected_malloc(m.count_line, m.len);
	return (m.result); //avant yavait un free line mais jcrois inutile
}

//total_length cest le nombre de points sur la map.
t_point	*parsing(char *map, int total_length, int one_line_len)
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
			handle_color(result + (i * one_line_len) + j, real_line[j]);
		}
		free(real_line);
		free(line);
		i++;
	}
	result[total_length].x = -1;
	return (result);
}
