/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:45:26 by alambert          #+#    #+#             */
/*   Updated: 2022/03/15 13:46:52 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_malmove(char *dest, char *src, int len1, int len2)
{
	char	*res;

	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_memmove((void *)(res), (void *)dest, len1);
	ft_memmove((void *)(res + len1), (void *)(src), len2 + 1);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len2 = ft_span(s2, "", -1);
	res = NULL;
	len1 = ft_span(s1, "", -1);
	res = ft_malmove(s1, s2, len1, len2);
	free(s1);
	return (res);
}
