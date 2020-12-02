#include <iostream>
using namespace std;
//Got help from geeksforgeeks.com and the textbook
int MAX(int x, int y, int a)
{
    return max(max(x, y), a);
}
int max(int x, int y){
    if(x > y){
        return x;
    }
    else{
        return y;
    }
}
int findMaxSum(int low, int mid, int high, int arr[])
{
    int sum = 0;
    int lSum = 0;
    int rSum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];
        if(sum > lSum)
        {
            lSum = sum;
        }
    }
    sum = 0;
     for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + arr[i];
        if(sum > rSum)
        {
            rSum = sum;
        }
    }
    int tSum = rSum + lSum;
    return MAX(tSum, lSum, rSum);
}
int maxSubArray(int low, int high, int arr[]){
    int sum = 0;
    int mid = (low + high)/2;
    if(high == low){
        if(arr[high]>0){
            sum = arr[high];
        }
        return sum;
    }
    return MAX(maxSubArray(low, mid, arr), maxSubArray(mid+1, high, arr), findMaxSum(low, mid, high, arr));
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
    int sum = maxSubArray(0, x-1, arr);
    cout<<sum;
}

