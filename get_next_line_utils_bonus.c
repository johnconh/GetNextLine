/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:43:39 by jdasilva          #+#    #+#             */
/*   Updated: 2022/09/30 18:44:31 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str ++;
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*dst;
	size_t	size;

	if (!str)
		return (0);
	size = ft_strlen(str);
	dst = (char *)malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < size)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	dst = (char *)malloc(sizeof(*dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (0);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	dst = (char *) malloc (sizeof(char) * len + 1);
	if (!dst)
		return (0);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (s[i] && j < len)
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}
