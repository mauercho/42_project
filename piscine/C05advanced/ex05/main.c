/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:30:00 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/20 16:31:20 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET  "\033[0m"

int	ft_sqrt(int nb);

void ex05(void) {
	printf(YELLOW "========== ex05 ==========\n"RESET );
	printf(YELLOW "TC #01          \n"RESET );
	printf("Testcase: sqrt(-10)\n");
	printf("Expected: %d\n", 0);
	printf("Result  : %d\n", ft_sqrt(-10));
	printf(YELLOW "TC #02          \n"RESET );
	printf("Testcase: sqrt(4)\n");
	printf("Expected: %d\n", 1);
	printf("Result  : %d\n", ft_sqrt(4));
	printf(YELLOW "TC #03          \n"RESET );
	printf("Testcase: sqrt(27)\n");
	printf("Expected: %d\n", 0);
	printf("Result  : %d\n", ft_sqrt(27));
	printf(YELLOW "TC #04          \n"RESET );
	printf("Testcase: sqrt(25)\n");
	printf("Expected: %d\n", 1);
	printf("Result  : %d\n", ft_sqrt(25));
	printf(YELLOW "TC #05          \n"RESET );
	printf("Testcase: sqrt(3844)\n");
	printf("Expected: %d\n", 1);
	printf("Result  : %d\n", ft_sqrt(3844));
	printf(YELLOW "TC #06          \n"RESET );
	printf("Testcase: sqrt(2000000000) "RED"[TLE!]\n"RESET);
	printf("Expected: %d\n", 0);
	printf("Result  : %d\n", ft_sqrt(2000000000));
	printf("\n");
}

int	main(void)
{
	ex05();
	return (0);
}
