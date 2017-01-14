#include <iostream>
#include<stdio.h>
#include<time.h>
#include<vector>
#include<stdlib.h>
#include "upperShift.h"
#include "random.h"
#include "print.h"
#include "leftShift.h"
#include "rightShift.h"
#include "lowerShift.h"
using namespace std;

int main()
{
    int arr[][4] = {{0 , 0, 0, 0} , {0 , 0, 0, 0} , {0 , 0, 0, 0} , {0 , 0, 0, 0}};
    Cell p = getRandom(arr);
    srand(time(NULL));
    int z = rand() % 4;
    if(z == 2)
        arr[p.r][p.c] = 4;
    else
        arr[p.r][p.c] = 2;
    Cell c = getRandom(arr);
    int sum = 0;
    while(c.c != -1 || c.r != -1)
    {
        c = getRandom(arr);
        if(c.c!=-1 || c.r!=-1)
        {
            srand(time(NULL));
            int x = rand() % 4;
            if(x == 2 && z!=2)
                arr[c.r][c.c] = 4;
            else
                arr[c.r][c.c] = 2;
            system("cls");
            print(arr);
            printf("                              ");
            printf("Score is : %d\n",sum);
            printf("\n");
            cout<<"***************************** Instructions *****************************"<<endl;
            cout<<"1. Press W to move left"<<endl;
            cout<<"2. Press S to move down"<<endl;
            cout<<"3. Press A to move left"<<endl;
            cout<<"4. Press D to move right"<<endl;
            cout<<endl;
            printf("\n");

            cout<<"Enter Your Choice : ";
            char ch;
            cin>>ch;
            if(ch == 'A')
            {
                for(int i = 0 ; i < 4 ; i++)
                {
                    leftShift(arr[i]);
                    sum+=addLeft(arr[i]);
                }
                //printf("After Left Shifting \n");
                //print(arr);
                printf("\n");
            }
            else if(ch == 'D')
            {
                for(int i = 0 ; i < 4 ; i++)
                {
                    rightShift(arr[i]);
                    sum+=addRight(arr[i]);
                }
                //printf("After Left Shifting \n");
                //print(arr);
                printf("\n");
            }
            else  if(ch == 'W')
            {
                upperShift(arr);
                sum+=addUpper(arr);
                //printf("After Left Shifting \n");
                //print(arr);
                printf("\n");
            }
            else if(ch =='S')
            {
                lowerShift(arr);
                sum+=addLower(arr);
                //printf("After Left Shifting \n");
                //print(arr);
                printf("\n");
            }
            else
            {
                c.r = -1;
                c.c = -1;
            }
        }
    }
    if(c.r == -1 || c.c == -1)
    {
        cout<<"********************* GAME OVER ***********************"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Score  : "<<sum<<endl;
        cout<<"-------------------------------------------------------"<<endl;

    }
    return 0;
}
