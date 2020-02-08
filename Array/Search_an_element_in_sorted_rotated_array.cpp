#include<bits/stdc++.h>
using namespace std;
int binarysearch (vector<int> arr, int low, int high, int key){
    if(high<low) return -1;
    if(high==low && arr[low]==key){
        return low;
    }
    int mid=low+(high-low)/2;
    if(key==arr[mid]){
        return mid;
    }
    if(key>arr[mid]){
        return binarysearch(arr,mid+1,high,key);
    }
    return binarysearch(arr,low,mid-1,key);
}
int findpivot (vector<int> arr, int low, int high){
    if (high < low) return -1;
    if (high == low) return low; 
    int mid  = low+(high-low)/2;
    if(mid>low && arr[mid]<arr[mid-1]){
        return mid-1;
    }
    if(mid<high && arr[mid]>arr[mid+1]){
        return mid;
    }
    if(arr[low]>=arr[mid]){
        return findpivot(arr,low,mid-1);
    }
    return findpivot(arr,mid+1,high);
}
int findindex (vector<int> arr, int key){
    int n = arr.size();
	int pivot = findpivot(arr,0,n-1);
	if (pivot == -1){
	    return binarysearch(arr, 0, n-1, key);
	}
	if(key==arr[pivot]){
	    return pivot;
	}
	if(arr[0]<=key){
	    return binarysearch(arr,0,pivot-1,key);
	}
	else{
	    return binarysearch(arr,pivot+1,n-1,key);
	}
}
int main() {
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(1);
	v.push_back(2);
	int n=v.size();
	int ans = findindex(v,6);
	cout<<ans;
	return 0;
}   