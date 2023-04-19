/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:04:21 by minwucho          #+#    #+#             */
/*   Updated: 2023/04/02 19:22:39 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zero_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (0);
	str[0] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	cnt;

	cnt = (size_t)start;
	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < (size_t)start)
		str = zero_str();
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		ft_strlcpy(str, &s[start], len + 1);
	}
	return (str);
}
