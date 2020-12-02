#include<iostream>
#include<vector>
using namespace std;
//Got help from oolmos98 on github
void countingSort (vector<int> arr[], int x, int index)
{
    vector<int> *outputArr = new vector<int>[x];
    int count[10] = {0};
    for (int i = 0; i< x; i++)
    {
        count[arr[i][index]]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    for (int i = x-1; i>=0; i--)
    {
        outputArr[count[arr[i][index]]-1] = arr[i];
        count[(arr[i][index])]--;
    }
    for (int i = 0; i < x; i++)
    {
        arr[i] = outputArr[i];
    }
    
}
void radixSort(vector<int> arr[], int x)
{
    for (int i = 10; i > 0; i--)
    {
        countingSort(arr, x, i - 1);
    }
}
int main()
{
    
    int x = 0;
    cin>>x;
    vector<int> *arr = new vector<int>[x];
    for (int i = 0; i<x; i++)
    {
        for( int j = 0; j <10; j++)
        {
            int temp;
            cin>>temp;
            arr[i].push_back(temp);
        }
       
    }
    radixSort(arr, x);
    for(int i = 0; i < x; i++)
    {
        for(vector<int>::iterator j = arr[i].begin(); j != arr[i].end(); j++)
        {
            cout<< *j <<";";
        }
        cout<<endl;
    }
    return 0;
}