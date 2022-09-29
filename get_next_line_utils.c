/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:27:35 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/29 17:27:37 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	i;

	i = 0;
	s1_len = ft_strlen(s1);
	str = (char *)ft_calloc(s1_len + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	alloc_size;

	alloc_size = nmemb * size;
	if (alloc_size / size != nmemb && size)
		return (NULL);
	alloc = malloc(alloc_size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, alloc_size);
	return (alloc);
}

size_t	ft_strlen(const char *args)
{
	size_t	l;

	l = 0;
	while (args[l])
		l++;
	return (l);
}
