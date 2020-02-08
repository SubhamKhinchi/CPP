#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    string s = "";
	    char ch[]={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
	    while(N>0){
	        if(N%26==0){
	            s+=ch[N%26];
	            N=(N/26)-1;
	        }
	        else{
	            s+=ch[N%26];
	            N=N/26;
	        }
	    }
	    string ans ="";
	    for(int i=s.size()-1; i>=0; i--){
	        ans+=s[i];
	    }
	    cout<<ans<<endl;
	}
	return 0;
}