#include<bits/stdc++.h>
#include<map>
using namespace std;

int rearrange (int arr[], int n){
    //-1, -1, 6, 1, 9, 3, 2, -1, 4, -1
    unordered_map<int, int> umap;
    for(int i=0; i<n; i++){
        umap[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        if(umap.find(i)!=umap.end()){
            arr[i]=i;
        }
        else{
            arr[i]=-1;
        }
    }
}


int main() {
	int arr[]={-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int len = sizeof(arr)/sizeof(arr[0]);
	rearrange(arr,len);
	for(int i=0; i<len; i++){
	    cout<<arr[i]<<endl;
	}
	return 0;
}
