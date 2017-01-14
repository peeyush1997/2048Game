#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void leftShift(int arr[])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		if(arr[i] == 0)
		{
			for(j = i+1 ;j < 4 ; j++)
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

int addLeft(int arr[])
{
	int i;
	int sum = 0;
	for(i = 0;i < 4; i++)
	{
		if(arr[i] == arr[i+1])
		{
			arr[i] += arr[i+1];
			sum+=arr[i];
			arr[i+1] = 0;
			leftShift(arr);
		}
	}
	return sum;
}
