/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:52:15 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/20 19:38:01 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	num;

	num = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb == 3)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (num < nb / num)
	{
		if (nb % num == 0)
			return (0);
		num += 1;
	}
	return (1);
}
