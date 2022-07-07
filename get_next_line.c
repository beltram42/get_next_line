/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:15:55 by alambert          #+#    #+#             */
/*   Updated: 2022/05/18 11:08:08 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	if (!*str)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_lines(char *str, int len, int nlen, int gear)
{
	char	*res;

	if (!*str)
		return (NULL);
	if (gear == 1 && nlen == len)
		res = malloc(sizeof(char) * nlen + 1);
	else if (gear == 1)
		res = malloc(sizeof(char) * nlen + 2);
	if (gear == 2 && nlen == len)
		res = malloc(sizeof(char));
	else if (gear == 2)
		res = malloc(sizeof(char) * (len - nlen));
	if (!res)
		return (ft_free(&str));
	if (gear == 1)
		ft_memmove(res, str, nlen + 1);
	if (gear == 1 && nlen != len)
		res[nlen + 1] = '\0';
	if (gear == 2 && nlen != len)
		ft_memmove(res, str + nlen + 1, len - nlen);
	else if (gear == 2)
		*res = '\0';
	if (gear == 2)
		free(str);
	return (res);
}

char	*ft_save(int fd, char *str)
{
	char	*save;
	int		len;

	save = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!save)
		return (NULL);
	len = 1;
	while (!ft_strchr(str, '\n') && len != 0)
	{
		len = read(fd, save, BUFFER_SIZE);
		if (len == -1)
		{
			free(save);
			return (NULL);
		}
		save[len] = '\0';
		str = ft_strjoin(str, save);
		if (!str)
			return (ft_free(&save));
	}
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*res;
	int			len;
	int			nlen;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_save(fd, buff);
	if (!buff)
		return (NULL);
	len = ft_span(buff, "", -1);
	nlen = ft_span(buff, "\n", -1);
	res = ft_lines(buff, len, nlen, 1);
	if (!res)
		return (ft_free(&buff));
	buff = ft_lines(buff, len, nlen, 2);
	if (!buff)
		return (NULL);
	return (res);
}
