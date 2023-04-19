/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_final.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:44:13 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/21 15:51:46 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int flag_a[10];
int flag_b[19];
int flag_c[19];
int pos[10];

void print(void)
{
    int i;
    for (i = 0; i < 10; i++)
        printf("%d", pos[i]);
    printf("\n");
}

void set(int i)
{
    int j;
    for (j = 0; j < 10; j++)
    {
        if(!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 9]){
            pos[i] = j;
            if (i == 9)
                print();
            else
            {
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 9] = 1;
                set(i + 1);
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 9] = 0;
            }
        }
    }
}

int main(void)
{
    int i;
    for (i = 0; i < 10; i++)
        flag_a[i] = 0;
    for (i = 0; i < 19; i++)
        flag_b[i] = flag_c[i] = 0;
    set(0);

    return (0);
}