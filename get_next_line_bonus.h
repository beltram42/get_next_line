/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:43:33 by alambert          #+#    #+#             */
/*   Updated: 2022/03/15 13:46:30 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(char *s, int c);
int		ft_span(char *str, char *set, int gear);
void	*ft_memmove(void *dst, void *src, int n);
char	*ft_malmove(char *dest, char *src, int len1, int len2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char **str);
char	*ft_lines(char *str, int len, int nlen, int gear);
char	*ft_save(int fd, char *str);
char	*get_next_line(int fd);

#endif
