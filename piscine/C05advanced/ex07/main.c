/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:44 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/20 18:59:58 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET  "\033[0m"

int	ft_find_next_prime(int nb);

void ex07(void) {
	printf(YELLOW "========== ex07 ==========\n"RESET );
	printf(YELLOW "TC #01          \n"RESET );
	printf("Testcase: 100\n");
	printf("Expected: %d\n", 101);
	printf("Result  : %d\n", ft_find_next_prime(100));
	printf(YELLOW "TC #02          \n"RESET );
	printf("Testcase: 468\n");
	printf("Expected: %d\n", 479);
	printf("Result  : %d\n", ft_find_next_prime(468));
	printf(YELLOW "TC #03          \n"RESET );
	printf("Testcase: 1\n");
	printf("Expected: %d\n", 2);
	printf("Result  : %d\n", ft_find_next_prime(1));
	printf(YELLOW "TC #04          \n"RESET );
	printf("Testcase: 123\n");
	printf("Expected: %d\n", 127);
	printf("Result  : %d\n", ft_find_next_prime(123));
	printf(YELLOW "TC #05          \n"RESET );
	printf("Testcase: 853\n");
	printf("Expected: %d\n", 853);
	printf("Result  : %d\n", ft_find_next_prime(853));
	printf(YELLOW "TC #06          \n"RESET );
	printf("Testcase: 65486 "RED"[TLE!]\n"RESET);
	printf("Expected: %d\n", 65497);
	printf("Result  : %d\n", ft_find_next_prime(65486));
	printf("\n");
}

int	main(void)
{
	long long	num;

	num = 2147483647;
	printf("%d\n\n\n\n", ft_find_next_prime(num));
	ex07();
	return (0);
}
