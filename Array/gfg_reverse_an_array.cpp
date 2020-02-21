#include<bits/stdc++.h>
using namespace std;

int reversearray(int arr[], int n){
    int start=0;
    int end = n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main(){
	int arr[]={1,2,3,4,5,6};
	int n= sizeof(arr)/sizeof(arr[0]);
	reversearray(arr,n);
	for(int i=0; i<n; i++){
	    cout<<arr[i]<<endl;
	}
	return 0;
}
