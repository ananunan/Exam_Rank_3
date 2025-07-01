/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:42:06 by aeberius          #+#    #+#             */
/*   Updated: 2025/07/01 15:44:30 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strdup(char *str)
{
	int	x;
	char	*dest;
	x = 0;
	while (str[x])
		x++;
	dest = (char *)malloc(sizeof(char) * (x + 1));
	x = 0;
	while(str[x])
	{
		dest[x] = str[x];
		x++;	
	}
	dest[x] = '\0';
	return(dest);
}
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	int		x;
	char		line[70000];
	static int	b_read;
	static int	b_pos;
	x = 0;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while(1)
	{
		if (b_pos >= b_read)
		{
			b_read = read(fd, buffer, BUFFER_SIZE);
			b_pos = 0;
			if (b_read <= 0)
				break;	
		}
		line[x++] = buffer[b_pos++];
		if(line[x - 1] == '\n')
			break;
	}
	line[x] = '\0';
	if(x == 0)
		return (NULL);
	return(ft_strdup(line));
}
