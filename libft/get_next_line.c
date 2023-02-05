/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:47:20 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*gnl_read_join(t_backup_list *here)
{
	char	*ret_line;
	char	buf[BUFFER_SIZE + 1];
	int		val_read;

	ret_line = gnl_strdup(here->backup);
	ft_free((void **)&here->backup);
	while (ret_line && gnl_strchr(ret_line, '\n') == 0)
	{
		val_read = read(here->fd, buf, BUFFER_SIZE);
		if (val_read < 0)
		{
			ft_free((void **)&ret_line);
			exit(EXIT_FAILURE);
		}
		else if (val_read == 0)
			break ;
		else
		{
			buf[val_read] = '\0';
			ret_line = gnl_strjoin(ret_line, buf);
		}
	}
	return (ret_line);
}

void	gnl_split_line(t_cont *ubox, t_backup_list *here)
{
	char	*index;

	index = gnl_strchr((*ubox).line, '\n');
	if (index == 0)
		(*ubox).ret = gnl_strdup((*ubox).line);
	else
	{
		(*ubox).ret = gnl_substr((*ubox).line, 0, index - (*ubox).line + 1);
		if ((*ubox).ret)
			here->backup = gnl_substr((*ubox).line, gnl_strlen((*ubox).ret), \
							gnl_strlen(index));
	}
	if (here->backup && *(here->backup) == '\0')
		ft_free((void **)&here->backup);
	ft_free((void **)&((*ubox).line));
}

t_backup_list	*gnl_search_add_list(t_backup_list **head, int fd)
{
	t_backup_list	*new_list;
	t_backup_list	*index;

	index = *head;
	while (index)
	{
		if (index->fd == fd)
			return (index);
		index = index->next;
	}
	new_list = ft_malloc(1, sizeof(t_backup_list));
	new_list->next = *head;
	*head = new_list;
	new_list->fd = fd;
	new_list->backup = NULL;
	return (new_list);
}

void	gnl_del_list(t_backup_list **head, t_backup_list *here)
{
	t_backup_list	*index;

	if (!(*head) || !here)
		return ;
	if (here->backup != 0)
		return ;
	if (*head == here)
	{
		*head = here->next;
		ft_free((void **)&here);
		return ;
	}
	index = *head;
	while (index->next != here)
		index = index->next;
	index->next = here->next;
	ft_free((void **)&here);
}

char	*get_next_line(int fd)
{
	static t_backup_list	*head;
	t_backup_list			*here;
	t_cont					ubox;

	here = gnl_search_add_list(&head, fd);
	if (!here->backup)
		here->backup = gnl_strdup("");
	ubox.line = gnl_read_join(here);
	ft_free((void **)&here->backup);
	if (ubox.line == 0)
		ubox.ret = NULL;
	else if (*ubox.line == '\0')
	{
		ft_free((void **)&ubox.line);
		return (NULL);
	}
	else
		gnl_split_line(&ubox, here);
	gnl_del_list(&head, here);
	return (ubox.ret);
}
