#include<iostream>
#include <limits.h>
using namespace std;

void POP(int **s, int i, int j)
{
    if(i==j)
    {
        cout<<"A"<<i-1;
        return;
    }
    else
    {
        cout<<"(";
        POP(s, i, s[i][j]);
        POP(s, s[i][j]+1, j);
        cout<<")";
    }
}
void MCO(int *p, int n)
{
    int **m = new int *[n];
    int **s = new int *[n];
    for(int i = 0; i<n; i++)
    {
        s[i] = new int[n];
        m[i] = new int[n];
    }
    for(int i = 0; i<n; i++)
    {
        m[i][i] = 0;
    }
    for(int i = 2; i<n; i++)
    {
        for(int j = 1; j<n-i+1; j++)
        {
            int x = j+i-1;
            m[j][x] = INT_MAX;
            for(int k = j; k<=x-1; k++)
            {
                int y = m[j][k] + m[k+1][x] + (p[j-1]*p[k]*p[x]);
                if(y < m[j][x])
                {
                    m[j][x] = y;
                    s[j][x] = k;
                }
            }
        }
    }
    cout<<m[1][n-1]<<endl;
    POP(s, 1, n-1);
    cout<<endl;
}
int main()
{
    int x;
    cin>>x;
    int *arr = new int[x+1];
    for(int i = 0; i<=x; i++)
    {
        cin>>arr[i];
    }
    MCO(arr, x+1);
}