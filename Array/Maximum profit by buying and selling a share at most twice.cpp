#include <bits/stdc++.h>
using namespace std;

int sumfun(vector<int> arr){
    int n = arr.size();
    int dp[n-1];
    for(int i=0; i<n-1; i++){
    	dp[i] = arr[i+1]-arr[i];
	}
	int p1=0, p2=0;
	for(int i=0;i<n-1; i++){
		for(int j = i+2; j<n; j++){
			for(int k=j+1; k<n;k++){
				if(p2<(arr[k]-arr[j])){
					p2 = (arr[k]-arr[j]);
					if(dp[i]>0){
						p1=dp[i];
					}
				}
			}
		}
	}
	return (p1+p2);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    vector<int> v;
	    for(int i=0; i<n; i++){
	        int val;
	        cin>>val;
			v.push_back(val);
	    }
	    cout<<sumfun(v);
	}
	
	return 0;
}
