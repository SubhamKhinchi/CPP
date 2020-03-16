#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
	return (a>b)? a: b;
}
int knapsackfun(int wt[],int pt[],int ct, int n){
	int dp[n][ct+1]={0};
	for(int w=0; w<=n; w++ ){
		dp[w][0]=0;
	}
	for(int c=0; c<ct; c++){
		if(wt[0]<=ct){
			dp[0][c]=pt[0];
		}
	}
	for(int w=1; w<n; w++){
		for(int c=1; c<=ct; c++){
			int p1=0, p2=0;
			if(wt[w]<=c){
				p1=pt[w]+dp[w-1][c-wt[w]];
			}
			else{
				p2=dp[w-1][c];
			}
			dp[w][c]=max(p1,p2);
		}
	}
	return dp[n-1][ct];
}


int main(){
	int w[] = { 2, 3, 1, 4 };
	int p[] = { 4, 5, 3, 7 };
	int n = sizeof(w)/sizeof(w[0]);
	int c = 6;
	cout<<knapsackfun(w,p,c,n);
	return 0;
}
