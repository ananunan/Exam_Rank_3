/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:54:53 by aeberius          #+#    #+#             */
/*   Updated: 2025/03/10 14:57:11 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char *start = malloc(10000);
	char *cursor = start;
	
	while(read(fd, cursor, 1) > 0)
	{
		if (*cursor == '\n')
			break;
		cursor++;
	}
	if (cursor > start)
	{
		*cursor = 0;
		return (start);
	}
	free(start);
	return (NULL);
	
}

// char *get_next_line(int fd) 
// {
//     char *s = malloc(10000), *c = s;
//     while (read(fd, c, 1) > 0 && *c++ != '\n');
//     return c > s ? (*c = 0, s) : (free(s), NULL);
// }

int	main()
{
	int fd = open("file", O_RDONLY);
	char *a;
	int i = 0;
	while (i < 6)
	{
		a =  get_next_line(fd);
		printf("Return : %s\n", a);
		free(a);
		i++;
	}
	
}