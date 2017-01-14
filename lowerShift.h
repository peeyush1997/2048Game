#include<stdio.h>

void lowerShift(int arr[][4])
{
	int i,j;
	for(i = 0;i < 4 ; i++)
	{
		for(j = 3;j > -1 ; j--)
		{
			if(arr[j][i] == 0)
			{
				int k;
				for(k = j-1; k > -1 ; k--)
				{
					if(arr[k][i]!=0)
					{
						int t = arr[k][i];
						arr[k][i] = arr[j][i];
						arr[j][i] = t;
						break;
					}
				}
			}
		}
	}
}

int addLower(int arr[][4])
{
	int i,j;
	int sum = 0;
	for(i = 0 ; i < 4; i++)
	{
		for(j = 3; j > 0 ; j--)
		{
			if(arr[j][i] == arr[j-1][i])
			{
				arr[j][i]+=arr[j-1][i];
				sum+=arr[j][i];
				arr[j-1][i] = 0;
				lowerShift(arr);
			}
		}
	}
	return sum;
}
