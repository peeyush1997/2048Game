#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

struct Cell
{
    int r;
    int c;
};

struct Cell getRandom(int matrix[][4])
{
    vector<Cell> v ;
    for(int i = 0; i < 4 ; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(matrix[i][j] == 0)
            {
                Cell c = { i , j};
                v.push_back(c);
            }
        }
    }
    if(v.size() == 0)
    {
        Cell c = {-1 , -1};
        return c;
    }
    else
    {
        srand(time(NULL));
        int x = rand() % v.size();
        return v[x];
    }
}
