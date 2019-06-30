/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:40:05 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/23 16:40:09 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char*)s;
	if ((char)c == '\0')
		return (ptr + ft_strlen(s));
	while (*ptr != '\0')
		if (*ptr++ == (char)c)
			return (--ptr);
	return (NULL);
}
