#include <bits/stdc++.h>
using namespace std;
int main() {
	double X;
	cin>>X;
	int N;
	cin>>N;
	double t=X*0.05;
	vector<pair<char, double> > p;
	int r=0;
	while(r<N){
	   char ch;
	   double n;
	   cin>>ch>>n;
	   if(n>=t){
	       p.push_back(make_pair(ch,n));
	       r++;
	   }
	   else{
	       r++;
	   }
	}
	sort(p.begin(),p.end());
	vector< pair <char,double> > vect;
	vector<double> dummy;
	for(int i=0; i<p.size(); i++){
	    for(int k=1; k<=14; k++){
	        double x = p[i].second/k;
	        vect.push_back(make_pair(p[i].first,x));
	        dummy.push_back(x);
	    }
	}
	sort(dummy.begin(),dummy.end());
	double target = dummy[dummy.size()-14];
	vector<pair<char, int> > ans;
	for(int i=0; i<vect.size(); i++){
	    if(vect[i].second>=target){
	        ans.push_back(make_pair(p[i/14].first,vect[i].second));
	    }
	}
	map<char, int> umap;
	for(int i=0; i<ans.size(); i++){
	    umap[ans[i].first]++;
	}
	for(auto i:umap){
	    cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}