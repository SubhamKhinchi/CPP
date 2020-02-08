#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    int d = k%n;
	    int temparr[n];
	    for(int i=0; i<n; i++){
	        if((i-d)>=0){
	            temparr[i-d]=arr[i];
	        }
	        else{
	            temparr[(i-d)+n]=arr[i];
	        }
	    }
	    for(int i=0; i<n; i++){
	        cout<<temparr[i]<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}