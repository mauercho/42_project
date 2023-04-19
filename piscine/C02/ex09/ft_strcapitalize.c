/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:54:47 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/21 09:56:34 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char alpha)
{
	if (!(alpha >= 'A' && alpha <= 'Z'))
	{
		if (alpha >= 'a' && alpha <= 'z')
			return (0);
		else if (alpha >= '0' && alpha <= '9')
			return (0);
		return (1);
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	idx;
	int	diff;

	diff = 'a' - 'A';
	idx = 0;
	while (str[idx] != 0)
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
		{
			str[idx] += diff;
		}
		idx++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	char	*dest;
	int		idx;

	idx = 0;
	dest = ft_strlowcase(str);
	if (dest[0] >= 'a' && dest[0] <= 'z')
		dest[0] -= 32;
	while (dest[idx] != 0)
	{
		if (check(dest[idx]))
			if (dest[idx + 1] >= 'a' && dest[idx + 1] <= 'z')
				dest[idx + 1] -= 32;
		idx++;
	}
	return (dest);
}
