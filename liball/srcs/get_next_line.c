/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 10:15:02 by abaker            #+#    #+#             */
/*   Updated: 2021/11/22 18:51:04 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*updatesave(char *save)
{
	char	*tmp;
	char	*rtn;

	tmp = ft_strchr(save, '\n');
	if (!tmp)
	{
		free(save);
		return (NULL);
	}
	tmp++;
	rtn = ft_strdup(tmp);
	free(save);
	return (rtn);
}

static char	*get_line(char *save)
{
	int	i;

	if (!save || save[0] == '\n' || save[0] == '\0')
		return (NULL);
	i = 0;
	while (!(save[i] == '\n' || save[i] == '\0'))
		i++;
	if (save[i] == '\n')
		i++;
	return (ft_substr(save, 0, i));
}

static char	*savebuff(char *save, char *buff)
{
	char	*tmp;

	if (!save)
		return (ft_strdup(buff));
	else
	{
		tmp = ft_strjoin(save, buff);
		free(save);
		return (tmp);
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*saves[1024];
	char		*line;
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (!ft_strchr(saves[fd], '\n') && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			break ;
		buffer[rd] = '\0';
		saves[fd] = savebuff(saves[fd], buffer);
	}
	free(buffer);
	line = get_line(saves[fd]);
	saves[fd] = updatesave(saves[fd]);
	return (line);
}
