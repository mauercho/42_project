/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:55:24 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/28 22:33:36 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add(int n1, int n2)
{
	return (n1 + n2);
}

int	minus(int n1, int n2)
{
	return (n1 - n2);
}

int	mul(int n1, int n2)
{
	return (n1 * n2);
}

int	div(int n1, int n2)
{
	return (n1 / n2);
}

int	mod(int n1, int n2)
{
	return (n1 % n2);
}
