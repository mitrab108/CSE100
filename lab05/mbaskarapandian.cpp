#include<iostream>
using namespace std;

//Got help from geeksforgeeks.org
void makeHeap(int arr[], int size, int i)
{
    int index = i;
    int left = (2*i) + 1;
    int right = (2*i) +2;

    if (arr[left] > arr[index] && left < size)
    {
        index = left;
    }
    if (arr[right] > arr[index] && right < size)
    {
        index = right;
    }
    if(index != i)
    {
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        makeHeap(arr, size, index);
    }
}
void heapSort(int arr[], int size)
{
    for(int i = (size/2)-1; i>= 0; i--)
    {
        makeHeap(arr, size, i);
    }
    for( int j = size - 1; j>0; j--)
    {
        int temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
        makeHeap(arr, j, 0);
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
    heapSort(arr, x);
    for(int i = 0; i<x; i++)
    {
        cout<<arr[i]<<";";
    }
}