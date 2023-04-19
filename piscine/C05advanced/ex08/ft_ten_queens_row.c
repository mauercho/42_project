/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:58 by minwucho          #+#    #+#             */
/*   Updated: 2023/02/21 15:43:27 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int pos[10];
int flag[10];

void print(void)
{
    int i;
    for (i = 0; i< 10; i++)
    {
        printf("%d", pos[i]);
    }
    printf("\n");
}

void set(int i)
{
    int j;
    
    for (j = 0; j < 10; j++)
    {
        if(!flag[j])
        {
            pos[i] = j;
            if (i == 9)
                print();
            else
            {
                flag[j] = 1;
                set(i + 1);
                flag[j] = 0;
            }
        }
    }
}

int main(void)
{
    int i;
    for (i = 0; i < 10; i++)
        flag[i] = 0;
    set(0);
    return (0);
}