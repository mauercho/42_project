/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:41:17 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/20 11:42:21 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET  "\033[0m"

int	ft_iterative_power(int nb, int power);

void ex02(void) {
	printf(YELLOW "========== ex02 ==========\n"RESET );
	printf(YELLOW "TC #01          \n"RESET );
	printf("Testcase: 4^8\n");
	printf("Expected: %d\n", 65536);
	printf("Result  : %d\n", ft_iterative_power(4, 8));
	printf(YELLOW "TC #02          \n"RESET );
	printf("Testcase: 0^0\n");
	printf("Expected: %d\n", 1);
	printf("Result  : %d\n", ft_iterative_power(0, 0));
	printf(YELLOW "TC #03          \n"RESET );
	printf("Testcase: 3^(-21)\n");
	printf("Expected: %d\n", 0);
	printf("Result  : %d\n", ft_iterative_power(3, -21));
	printf(YELLOW "TC #04          \n"RESET );
	printf("Testcase: 128^10\n");
	printf("Expected: Undefined Behavior\n");
	printf("Result  : %d\n", ft_iterative_power(128, 128));
	printf(YELLOW "TC #05          \n"RESET );
	printf("Testcase: 0^10\n");
	printf("Expected: 0\n");
	printf("Result  : %d\n", ft_iterative_power(0, 10));
	printf(YELLOW "TC #06          \n"RESET );
	printf("Testcase: 10^0\n");
	printf("Expected: 1\n");
	printf("Result  : %d\n", ft_iterative_power(10 , 0));
	printf("\n");
}

int	main(void)
{
	ex02();
	return (0);
}
