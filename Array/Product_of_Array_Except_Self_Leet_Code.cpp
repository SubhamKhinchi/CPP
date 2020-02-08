vector<int> productExceptSelf(vector<int>& nums) {
    long long int multiply=1;
    int n=nums.size();
    int zerocount=0;
    for(int i=0; i<n; i++){
        if(nums[i]==0)
        {
            zerocount++;
            continue;
        }
        multiply=multiply*nums[i];
    }
    if(zerocount>1){
            vector<int>v(n,0);
            return v;
        }
    vector<int> vec,temp;
    for(int j=0; j<n; j++){
        if(nums[j]!=0){
            vec.push_back(multiply/nums[j]);
            temp.push_back(0);
        }
        else{
            temp.push_back(multiply);
        }
    }
    for(int k=0; k<n; k++){
        if(nums[k]==0){
            
            return temp;
        }
    }
    return vec;
}