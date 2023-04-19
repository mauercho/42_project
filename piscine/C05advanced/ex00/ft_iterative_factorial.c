/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:06:30 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/20 11:30:24 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	num = 1;
	while (nb >= 1)
	{
		num *= nb;
		nb--;
	}
	return (num);
}
