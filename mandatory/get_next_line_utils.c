/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:20:20 by apiloian          #+#    #+#             */
/*   Updated: 2023/02/09 19:20:22 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strlcpy(char *dest, char *src, size_t size, int flag)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	if (flag == 1)
		free(src);
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*str;

	str = malloc(ft_strlen(src, 0) * sizeof(char) + 1);
	if (!str)
		return (0);
	ft_strcpy(str, src);
	return (str);
}
