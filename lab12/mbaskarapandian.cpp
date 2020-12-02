#include<iostream>
#include<limits.h>
using namespace std;

//Got help from textbook and github

int rods;

int cutRod(int p[], int x, int n[])
{
    int val[x+1];
    int temp[x+1];
    val[0] = 0;
    for(int i = 1; i<=x; i++)
    {
        int a = -1;
        int max = INT_MIN;
        for(int j = 0; j<i; j++)
        {
            if(max<(p[j]+val[i-j-1]))
            {
                a = j;
                max = p[j] + val[i-j-1];
            }
        }
        val[i]= max;
        temp[i] = a+1;
    }
    int i = x;
    int j = 0;
    while(i>0)
    {
        n[j++] = temp[i];
        i-=temp[i];
    }
    rods = j;
    return val[x];
}

int main()
{
    int x;
    cin>>x;
    int price[x];
    for(int i = 0; i<x; i++)
    {
        cin>>price[i];
    }
    int n[x+1];
    cout<<cutRod(price, x, n)<<endl;
    cout<<n[0];
    for(int i = 1; i<rods; i++)
    {
        cout<<" "<<n[i];
    }
    cout<<" -1"<<endl;
}