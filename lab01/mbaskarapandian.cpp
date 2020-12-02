#include <iostream>
using namespace std;
int main(int argc, char **argv){
        int x;
        int y = -1;
        cin>>x;
        int* arr = new int[x];
        for(int i = 0; i<x+1; i++){
                cin>>arr[i];
        }
        for(int i = 1; i<x+1; i++){
            if(arr[i] == arr[0]){
                y = i-1;
            }
        }
        cout<<y<<endl;
return 0;
}
