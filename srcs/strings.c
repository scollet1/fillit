/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:33:35 by iwagner           #+#    #+#             */
/*   Updated: 2017/04/05 23:34:00 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (ft_strlen(src) < len)
	{
		while (i < len)
		{
			dst[i] = 0;
			i++;
		}
	}
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(&s1[ft_strlen(s1)], s2);
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i] != 0)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
