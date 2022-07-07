/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:25:35 by alambert          #+#    #+#             */
/*   Updated: 2022/05/09 16:11:02 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (s && *s != (char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

int	ft_span(char *str, char *set, int gear)
{
	char	*p;
	char	*s;

	if (!str)
		return (0);
	p = str;
	while (*p)
	{
		s = set;
		s = ft_strchr(s, *p);
		if (s == 0 && gear == 1)
			break ;
		if (s != 0 && gear == -1)
			break ;
		else
			p++;
	}
	return (p - str);
}

void	*ft_memmove(void *dest, void *src, int n)
{
	char		*startd;
	char		*starts;
	char		*ends;
	char		*endd;

	starts = (char *)src;
	startd = (char *)dest;
	ends = starts + (n - 1);
	endd = startd + (n - 1);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (startd < starts)
		while (n--)
			*startd++ = *starts++;
	else
		while (n--)
			*endd-- = *ends--;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len2 = ft_span(s2, "", -1);
	res = NULL;
	len1 = ft_span(s1, "", -1);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_memmove((void *)(res), (void *)s1, len1);
	ft_memmove((void *)(res + len1), (void *)(s2), len2 + 1);
	free(s1);
	return (res);
}
