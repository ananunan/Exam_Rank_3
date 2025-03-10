/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:57:44 by aeberius          #+#    #+#             */
/*   Updated: 2025/03/10 15:01:31 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "gnl_2.h"

char	*get_next_line(int fd)
{
	char tmp[800000];
	char buff[0];
	char *line;
	int i = 0;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp[0] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		tmp[i] = buff[0];
		tmp[i + 1] = '\0';
		if (tmp[i] == '\n')
		{ 
			i++;
			break ;
		}
		i++;
	}
	if (tmp[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}