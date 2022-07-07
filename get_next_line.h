/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:58:44 by alambert          #+#    #+#             */
/*   Updated: 2022/05/25 12:33:23 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "lib42.h"
# include <unistd.h>
# include <stdlib.h>

//char	*ft_strchr(char *s, int c);
//int		ft_span(char *str, char *set, int gear);
//void	*ft_memmove(void *dest, void *src, int n);
//char	*ft_strjoin(char *s1, char *s2);
//char	*ft_free(char **str);
char	*ft_malmovebis(char *dest, char *src, int len1, int len2);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ft_lines(char *str, int len, int nlen, int gear);
char	*ft_save(int fd, char *str);
//char	*get_next_line(int fd);
char	*ft_get_next_line(int fd);

#endif
