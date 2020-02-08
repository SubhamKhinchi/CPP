#include <bits/stdc++.h>
using namespace std;
void leftrotationbyone(int v[],int n){
    //one time left rotattion
    //n size
    int temp = v[0];
    int i;
    for(i=0; i<n-1; i++){
        v[i]=v[i+1];
    }
    v[i]=temp;
}
int sumfun (int arr[],int x){
    int maxele=INT_MIN;
    int idx=0;
    for(int i=0; i<x; i++){
        if(arr[i]>maxele){
            maxele=arr[i];
            idx=i;
        }
    }
    int cyc = idx+1;
    while(cyc--){
        leftrotationbyone(arr,x);
    }
    long long int sum = 0;
    for(int i=0; i<x; i++){
        sum+=(i*arr[i]);
    }
    return sum;
}



int main() {
	int vrr[]= {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout<<sumfun(vrr,10);
	return 0;
}
