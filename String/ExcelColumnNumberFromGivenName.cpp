#include <bits/stdc++.h>
using namespace std;
char ch[] = {'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
int findindex(char c){
    int idx;
    for(int j=0; j<26; j++){
        if(ch[j]==c){
            idx=j;
        }
    }
    return idx;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string s;
	    cin>>s;
	    string dummy="";
	    for(int i =s.size()-1; i>=0; i--){
	        dummy+=s[i];
	    }
	    long long int ans = 0;
	    for(int i=0; i<dummy.size(); i++){
	        int idxx = findindex(dummy[i]);
	       ans+=idxx*(pow(26,i));
	    }
	    cout<<ans;
	}
}