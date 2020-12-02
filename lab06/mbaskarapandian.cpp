#include<iostream>
#include <utility>
#include <ctime>
#include <cstdlib>
using namespace std;
//Got help from textbook and oolmos98 on Github
int partition(int arr[], int low, int high)
{
    int index = arr[high];
    int x = low - 1;
    for (int i = low; i <= high-1; i++)
    {
        if(arr[i] <= index)
        {
            x++;
            int temp = arr[x];
            arr[x] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[x+1];
    arr[x+1] = arr[high];s
    arr[high] = temp;
    return (x+1);
}
int randPar(int arr[], int p, int r)
{
    srand(time(NULL));
    int i = rand() % (r-p) + p;
    int temp = arr[i];
    arr[i] = arr[p];
    arr[p] = temp;
    return partition(arr, p, r);
}
void quickSort(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = randPar(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}
int main()
{
    
    int x;
    cin>>x;
    int arr[x];
    for (int i = 0; i<x; i++)
    {
        cin>>arr[i];
    }
    quickSort(arr, 0, x-1);
    for(int i = 0; i < x; i++)
    {
        cout<<arr[i]<<";";
    }
}
