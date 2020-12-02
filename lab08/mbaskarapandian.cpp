#include<iostream>
#include <vector> 
#include <algorithm>
using namespace std;
//Got help from Textbook and tutorialpoint.com
void bucketSort(double arr[], int x)
{
    vector<double> arr2[x];
    int a = 0;
    for(int i = 0; i<x; i++)
    {
        int index = x*arr[i];
        arr2[index].push_back(arr[i]);
    }
    for(int i = 0; i<x; i++)
    {
        sort(arr2[i].begin(),arr2[i].end());
    }
    for(int i = 0; i<x; i++)
    {
        for(int k = 0; k<arr2[i].size(); k++)
        {
            arr[a++] = arr2[i][k];
        }
    }
    
}
int main()
{
    
    int x;
    cin>>x;
    double arr[x];
    for (int i = 0; i<x; i++)
    {
        cin>>arr[i];
    }
    bucketSort(arr, x);
    for(int i = 0; i < x; i++)
    {
        cout<<arr[i]<<endl;
    }
}