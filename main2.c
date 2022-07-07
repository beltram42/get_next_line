/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:40:14 by alambert          #+#    #+#             */
/*   Updated: 2022/03/15 13:34:48 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	int fd1;

	fd = open("sjp1.txt", O_RDONLY);
	fd1 = open("sjp2.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	return (0);
}

/*
int	main(int ac, char **av)
{
	int fd;
	char *line = "ok";

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
 	       free(line);
	}
	free(line);
	return (0);
}
*/
