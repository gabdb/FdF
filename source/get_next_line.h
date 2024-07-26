/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:43:49 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/25 14:43:56 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	ssize_t			len;
}					t_list;

t_list				*ft_lstnew(char *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
char				*ft_strchr_bis(t_list *lst, int c, int loop);
char				*ft_strdup(const char *s1);
void				ft_strjoin_bis(char *line, t_list *node, size_t len);
t_list				**free_node(t_list **node, int loop);
char				*get_line_from_list(t_list *lst);
void				clean_buffer(t_list **lst);
int					read_to_buffer(int fd, t_list **lst);
char				*get_next_line(int fd);

#endif