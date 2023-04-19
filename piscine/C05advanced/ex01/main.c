/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:25:33 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/20 11:26:32 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET  "\033[0m"


int	ft_recursive_factorial(int nb);

void ex01(void) {
	printf(YELLOW "========== ex01 ==========\n"RESET );
	printf(YELLOW "TC #01          \n"RESET );
	printf("Testcase: 4!\n");
	printf("Expected: %d\n", 24);
	printf("Result  : %d\n", ft_recursive_factorial(4));
	printf(YELLOW "TC #02          \n"RESET );
	printf("Testcase: 6!\n");
	printf("Expected: %d\n", 720);
	printf("Result  : %d\n", ft_recursive_factorial(6));
	printf(YELLOW "TC #03          \n"RESET );
	printf("Testcase: 12!\n");
	printf("Expected: %d\n", 479001600);
	printf("Result  : %d\n", ft_recursive_factorial(12));
	printf(YELLOW "TC #04          \n"RESET );
	printf("Testcase: 20!\n");
	printf("Expected: Undefined Behavior\n");
	printf("Result  : %d\n", ft_recursive_factorial(20));
	printf("\n");
}

int main(void)
{
	ex01();
}
