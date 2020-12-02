#include <iostream>
using namespace std;
//Got help from geekforgeeks.org for the insert function
int h1 (int val)
{
    return (val%13);
}
int h2 (int val)
{
    return(1 + (val%11));
}
int DD (int h1, int h2, int i)
{
    return ((h1+(i*h2))%13);
}
void Insert(int val, int hash[])
{
    int f1 = h1(val);
    int f2 = h2(val);
    int i = 1;
    int x = 0;
    if (hash[f1] != -1)
    {
        for (i; i<13; i++)
        {
            int dhash = DD(f1, f2, i);
            if(hash[dhash] == -1)
            {
                hash[dhash] = val;
                break;
            }
        } 
    }
    if(hash[f1] == -1)
    {
        hash[f1] = val;
    }
}
void Delete (int val, int hash[])
{
    for(int i = 0; i<13; i++)
    {
        if(hash[i] == val)
        {
            hash[i] = -1;
        } 
    }
}
void Search (int val, int hash[])
{
    int count = 0;
    for(int i = 0; i<13; i++)
    {
        if(hash[i] == val)
        {
            cout<<i<<endl;
            count = 1;
        }
        
    }
    if(count != 1)
    {
        cout<<"NOT_FOUND"<<endl;
    }

}
void Print(int hash[])
{
    cout<<"++++table printout++++"<<endl;
    for (int i = 0; i<13; i++)
    {
        if(hash[i] == -1)
        {
            cout<<endl;
        }
        else
        {
            cout<<hash[i]<<endl;
        }
        
    }
}
int main()
{
    int hash[13];
    int val;
    for (int i = 0; i<13; i++)
    {
        hash[i] = -1;
    }
    while (val != -1)
    {
        cin>>val;
        if(val != -1)
        {
            Insert(val, hash);
        }
        else
        {
            Print(hash);
        }
    }
    cout<<"++++searching++++"<<endl;
    while (val != -2)
    {
        cin>>val;
        if(val != -2)
        {
            Search(val, hash);
        }
    }
    cout<<"++++deleting++++"<<endl;
    while (val != -3)
    {
        cin>>val;
        if(val != -3)
        {
            Delete(val, hash);
        }
        else
        {
            Print(hash);
        }
    }                 
}
