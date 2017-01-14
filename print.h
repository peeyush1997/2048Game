#include<stdio.h>
#include<iostream>

void print(int arr[][4])
{
    int i,j;
    for(i = 0 ;i < 4 ; i++)
    {
        printf("                    ------------------------------\n");
        printf("                    |");
        for(j = 0;j < 4; j++)
        {
            printf("   %d  |",arr[i][j]);
        }
        printf("\n");
    }
        printf("                    ------------------------------\n");
}
