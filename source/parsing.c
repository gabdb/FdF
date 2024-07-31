/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:25:35 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/31 17:48:31 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	args_exit(void)
{
	write(1, "wrong number arguments !\n", 25);
	exit(EXIT_FAILURE);
}

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

void	color(t_point *point, char *map_point)
{
	int	i;

	i = 0;
	while (map_point[i] && map_point[i] != ',')
		i++;
	if (map_point[i] != ',')
	{
		(*point).color = 0xFFFFFF;
		return ;
	}
	i += 3;
	(*point).color = my_atoi_base(map_point + i);
}

int	*check_map(int ac, char **argv)
{
	t_map	m;

	if (ac != 2)
		args_exit();
	m.fd = open(argv[1], O_RDONLY);
	if (-1 == m.fd)
		exit_msg();
	m.line = get_next_line(m.fd);
	if (!m.line || *m.line == '\0')
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
	return (free(m.line), m.result);
}

t_point	*parsing(char *map, int total_length, int one_line_len)
{
	t_pars	p;

	p.result = special_malloc(total_length);
	p.fd = safe_open(map, p.result);
	p.i = 0;
	while ((p.i * one_line_len) < total_length)
	{
		p.line = get_next_line(p.fd);
		p.real_line = ft_split(p.line, ' ');
		if (!p.real_line)
			free_line_result_exit(p.result, p.line);
		p.j = -1;
		while (p.real_line[++p.j] != NULL)
		{
			(p.result[(p.i * one_line_len) + p.j]).x = p.j;
			(p.result[(p.i * one_line_len) + p.j]).y = p.i;
			(p.result[(p.i * one_line_len)
					+ p.j]).z = ft_atoi(p.real_line[p.j]);
			color(p.result + (p.i * one_line_len) + p.j, p.real_line[p.j]);
		}
		mega_free(p.line, p.real_line);
		p.i++;
	}
	p.result[total_length].x = -1;
	return (p.result);
}
