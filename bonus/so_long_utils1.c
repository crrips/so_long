/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:55:17 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/22 19:55:17 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str, int flag)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		if (flag == 0)
			i++;
		else
		{
			if (*str != 'P' && *str != '1' && *str != '0' && *str != 'X'
				&& *str != 'C' && *str != 'E' && !(*str < 32))
				print_error("Error!\nUnknown key!");
			if (!(*str >= 9 && *str <= 13))
				i++;
		}
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;

	if (!s1 || !s2)
		return (0);
	new_str = malloc(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1);
	if (!new_str)
		return (0);
	i = 0;
	while (*s1)
	{
		new_str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = 0;
	return (new_str);
}

int	len(int n)
{
	int	size;

	size = 0;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		size;

	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	size = len(n);
	number = malloc(size + 1);
	if (!number)
		return (0);
	number[size] = 0;
	while (size--)
	{
		if (n < 10)
		{
			number[size] = n % 10 + '0';
			n /= 10;
			break ;
		}
		number[size] = n % 10 + '0';
		n /= 10;
	}
	return (number);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}
