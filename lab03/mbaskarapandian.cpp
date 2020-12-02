#include <iostream>
using namespace std;
//Got Help from old lab submission
void merge(int arr[], int left, int mid, int right){
    int temp = mid-left+1;
    int temp2 = right - mid;
int tempArr[temp];
int tempArr2[temp2];
for(int i = 0; i<(mid-left+1); i++)
    tempArr[i] = arr[left +i];
for(int j = 0; j<(temp2); j++)
    tempArr2[j] = arr[j+ mid +1];
int i= 0;
int j = 0;
int x = left;
while (i < (mid-left+1) && j < (temp2)){
if(tempArr[x] <= tempArr2[j])
{
arr[x] = tempArr[i];
i++;
}
else{
arr[x] = tempArr2[j];
j++;
}
x++;
}
while (i < (mid-left +1)){
arr[x] = tempArr[i];
i++;
x++;
}
while (j < (right- mid)){
arr[x] = tempArr2[j];
j++;
x++;
}
}
void mergeSort(int arr[], int left, int right){
if(left<right){
int mid = (left+(right-1))/2;
mergeSort(arr, left, mid);
mergeSort(arr, mid+1, right);
merge(arr, left, mid, right);
}
}
int main(int argc, char **argv){
int x;
cin>>x;
int arr[x];
for(int i = 0; i<x; i++){
cin>>arr[i];
}
mergeSort(arr, 0, x);
for(int j = 0; j<x; j++){
cout<<arr[j]<<";";
}
}


