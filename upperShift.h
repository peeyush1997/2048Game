#include<stdio.h>

void upperShift(int arr[][4])
{
	int i,j;
	j = 0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(arr[i][j]==0)
			{
				for(int k = i+1;k < 4; k++)
				{
					if(arr[k][j]!=0)
					{
						int t = arr[i][j];
						arr[i][j]= arr[k][j];
						arr[k][j] = t;
						break;
					}
				}
			}
		}
	}
}

int addUpper(int arr[][4])
{
    int sum = 0;
	for(int i = 0 ;i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(arr[j][i] == arr[j+1][i])
			{
				arr[j][i]+=arr[j+1][i];
				sum+=arr[j][i];
				arr[j+1][i] = 0;
				upperShift(arr);
			}
		}
	}
	return sum;
}
