#include <iostream>
using namespace std;
int binarySearch (int arr[], int x, int min, int max){
    int y = -1;
    while(min <= max){
        int mid = (min + max)/2;
        if(arr[mid] == x){
	    y = mid-1;
	    break;
        }
        if(arr[mid] < x){
            min = mid+1;
        }
        if(arr[mid] > x){
            max = mid-1;
        }
    }
    return y;
}
int main(int argc, char **argv){
        int x;
        cin>>x;
        int arr[x];
        for(int i = 0; i<=x; i++){
                cin>>arr[i];
        }
        int y = binarySearch(arr, arr[0], 1, x);
        cout<<y;
}
