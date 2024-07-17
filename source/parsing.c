/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:25:35 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/17 13:20:33 by gnyssens         ###   ########.fr       */
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
	int		*result; // [count_lines, one_line_len]
	int		fd;
	int		len;
	int		count_line;
	char	*line;

	if (ac != 2)
		exit(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
		return (0);
	line = get_next_line(fd);
	if (!line || *line == '\0') //si *line == '\0' faudra free !
		return (printf("empty map !\n"), NULL);
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
				return (free(line), printf("map not square !\n"), NULL);
		}
	}
	result = (int *)malloc(2 * sizeof(int)); //pas protégé, 2 places ca passe
	if (!result)
		exit(EXIT_FAILURE); //faut free line aussi
	*result = count_line;
	*(result + 1) = len;
	return (free(line), result);
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
	//result[total_length].y = -1;
	//result[total_length].z = -1;

	return (result);
}

/*
int main(int ac, char **av)
{
	int		*result;
	//int 	one_line_len;
	t_point	*test;

	if (access(av[1], F_OK) == -1) //à enlever, cest au cas ou la map nexiste pas (path oublié)
    {
        perror("Error");
        printf("File '%s' does not exist.\n", av[1]);
        return 1;
    }
	result = check_map(ac, av); //result est malloqué, donc free !
	test = parsing(av[1], result[0] * result[1], result[1]);
	free(result);

	fill_in_proj(test);
	int i = -1;
	while (test[++i].x != -1)
		printf("x = %f, y = %f, z = %f, color = %X, x_proj: %f and y_proj: %f\n", test[i].x, test[i].y, test[i].z, test[i].color, test[i].x_proj, test[i].y_proj);
	free(test);

	return 0;
}
*/