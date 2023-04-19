/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:18:08 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/28 22:59:07 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		add(int n1, int n2);
int		minus(int n1, int n2);
int		mul(int n1, int n2);
int		div(int n1, int n2);
int		mod(int n1, int n2);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

int	check(char alpha, char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != 0)
	{
		if (alpha == str[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

void	calculate(int n1, int n2, int idx)
{
	int	(*f[5])(int, int);

	f[0] = add;
	f[1] = minus;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	ft_putnbr(f[idx](n1, n2));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		n1;
	int		n2;
	char	*op;

	op = "+-*/%";
	if (argc != 4)
		return (0);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	if (n2 == 0 && argv[2][0] == '/')
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (n2 == 0 && argv[2][0] == '%')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	if (check(argv[2][0], op) == -1)
		write(1, "0\n", 2);
	else
		calculate(n1, n2, check(argv[2][0], op));
	return (0);
}
