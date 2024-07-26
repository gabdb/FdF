/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:45:29 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/25 14:45:54 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new_elem;

	if (content)
	{
		new_elem = (t_list *)malloc(sizeof(t_list));
		if (!new_elem)
			return (NULL);
		new_elem->content = content;
		new_elem->next = NULL;
		new_elem->len = 0;
		while (content[new_elem->len] != '\0')
			new_elem->len++;
		return (new_elem);
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

char	*ft_strchr_bis(t_list *lst, int c, int loop)
{
	const char	*s;

	while (lst)
	{
		s = lst->content;
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
		if (c == '\0')
			return ((char *)s);
		lst = lst->next;
		if (!loop)
			break ;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_strjoin_bis(char *line, t_list *node, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (node && i < len)
	{
		tmp = node->content;
		while (*tmp && *tmp != '\n' && i < len)
			line[i++] = *tmp++;
		if (*tmp == '\n' && i < len)
			line[i++] = *tmp++;
		node = node->next;
	}
	line[i] = '\0';
}
