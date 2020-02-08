#include <bits/stdc++.h>
using namespace std;
double medianofarrays(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size(); 
    int m = arr2.size();
    if(n>m){ //arr1 should be smaller array.
        vector<int> temp;
        int t;
        t=n;
        n=m;
        m=t;
        temp = arr1;
        arr1=arr2;
        arr2=temp;
    }
    //partition process
    int start = 0; 
    int end = n;
    int partition_arr1, partition_arr2;
    double median;
    
    while(start<=end){
        partition_arr1 = (start+end)/2;
        partition_arr2 = ((n+m+1)/2)-partition_arr1;
        //if partition_arr1 is 0 it means there us nothing on the left side of
        //the arr1 
        
        int MaxLeft_arr1 = (partition_arr1 == 0) ? INT_MIN : arr1[partition_arr1-1];
        int MinRight_arr1 = (partition_arr1 == n) ? INT_MAX : arr1[partition_arr1];        
        //if partition_arr2 is 0 it means there us nothing on the left side of
        //the arr2
        int MaxLeft_arr2 = (partition_arr2==0) ? INT_MIN : arr2[partition_arr2-1];
        int MinRight_arr2 = (partition_arr2==m) ? INT_MAX : arr2[partition_arr2];
        
        if(MaxLeft_arr1<=MinRight_arr2 && MaxLeft_arr2<=MinRight_arr1){
            //it meana we have reached the write partition.
            //now we have two case there
            //case 1 : total lenght(n+m) is even
            if((n+m)%2==0){
                int left = max(MaxLeft_arr1, MaxLeft_arr2);
                int right = min(MinRight_arr1, MinRight_arr2);
                median =(left+right)/2;
                return median;
            }
            //case 2 : total lenght (n+m) is odd.
            else{
                median = max(MaxLeft_arr1, MaxLeft_arr2);
                return median;
            }
        }
        else if(MaxLeft_arr1>MinRight_arr2){
            end=partition_arr1-1;
        }
        else{ // MaxRight_arr2 > MinRight_arr1
            start=partition_arr1+1;
        }
    }
    return median;
    
}
int main(){
    vector<int>v1,v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(8);
    v1.push_back(9);
    
//
    v2.push_back(7);
    v2.push_back(11);
    v2.push_back(18);
    v2.push_back(19);
    v2.push_back(21);
    v2.push_back(25);
    cout<<medianofarrays(v1,v2)<<endl;
    return 0;
}