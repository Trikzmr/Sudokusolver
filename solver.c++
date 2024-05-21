#include <iostream>
using namespace std;


int c = 0;

int count(int arr[4][4])
{
    int n = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(arr[i][j] == 0)
            n++;
        }
    }
    return n;
}

int possible(int arr[4][4], int x, int y, int num)
{
    //cout<<num;
    for(int i = 0; i <4; i++)
    {
        //cout<<"num: "<<num<<"ele: "<<arr[i][x]<<"\n";
        if(arr[x][i] == num)
        {
            return -1;
        }
    }
    for(int i = 0; i <4; i++)
    {
        //cout<<"num: "<<num<<"ele: "<<arr[i][x]<<"\n";
        if(arr[i][y] == num)
        {
            return -1;
        }
    }
    //cout<<"\n";
    
    return 0;
}
void solver(int arr[4][4], int n)
{
    if(c == n)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j <4; j++)
            {
                cout<<arr[i][j]<<"\t";
            }
            cout<<"\n";
        }
        return;
    }
    int f = 0;
    for(int i = 0; i< 4; i++)
    {
        
        for(int j = 0; j < 4; j++)
        {
            if(arr[i][j] == 0)
            {
                for(int k = 1; k<=4; k++)
                {
                    
                    if(possible(arr, i, j, k) == 0)
                    {
                        arr[i][j] = k;
                        c++;
                        solver(arr, n);
                        arr[i][j] = 0;
                        c--;
                    }
                    //cout<<possible(arr, i, j, k)<<"\n";
                }
                if(f == 0)
                {
                    return;
                }
            }
        }
    }
    return;
}

int main() {
  int arr[4][4] = {
      {0, 0, 3, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 1},
      {3, 0, 2, 0}
  };
  for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j <4; j++)
            {
                cout<<arr[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\n";cout<<"\n";cout<<"\n";
  int n = count(arr);
  
  solver(arr, n);
  return 0;
}