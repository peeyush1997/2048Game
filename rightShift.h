#include<stdio.h>
#include<stdlib.h>

void rightShift(int arr[])
{
	int i,j;
	for(i = 3; i > -1; i--)
	{
		if(arr[i]==0)
		{
			for(j = i-1;j > -1 ; j--)
			{
				if(arr[j]!=0)
				{
					int t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
					break;
				}
			}
		}
	}
}

int addRight(int arr[])
{
	int i;
	int sum = 0;
	for(i = 3;i > -1;i--)
	{
		if(arr[i] == arr[i-1])
		{
			arr[i]+=arr[i-1];
			sum+=arr[i];
			arr[i-1] = 0;
			rightShift(arr);
		}
	}
	return sum;
}
