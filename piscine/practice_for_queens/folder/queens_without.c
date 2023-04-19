#include <stdio.h>

void print(int arr[10])
{
    int i;

    i = 0;
    while (i < 10)
    {
        printf("%d", arr[i]);
        i++;
    }
    printf("\n");
}

void set(int i)
{
    int arr[10];
    int j;

    j = 0;
    while (j < 10)
    {
        if (i == 9)
        {
            print(arr);
            return ;
        }
        else
        {
            arr[i] = j;
            set(i + 1);
        }
        j++;
    }
}


int main(void)
{
    set(0);
    return (0);
}