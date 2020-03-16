#include <bits/stdc++.h>
using namespace std;

int sumfun(int arr[], int s){
    int maxsum = INT_MIN;
    int sum = 0;
    for(int i= 0; i<s; i++){
        sum+=arr[i];
        
        if(maxsum<sum){
            maxsum=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxsum;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int v[n];
	    for(int i=0; i<n; i++){
	        int val; cin>>val;
	        v[i]=val;
	    }
	    cout<<sumfun(v,n);
	}
	
	return 0;
}
